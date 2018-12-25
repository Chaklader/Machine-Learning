'''
File:  marketsim.py
Class:  Market Simulator for Computational Investing Class - Georgia Tech
Author: Boris Litinsky
Date:   10/15/2014
Description: Given cash, orders in a csv file, generates daily portfolio values
'''

import pandas as pd
import numpy as np
import math
import copy
import QSTK.qstkutil.qsdateutil as du
import datetime as dt
import QSTK.qstkutil.DataAccess as da
import QSTK.qstkutil.tsutil as tsu
import QSTK.qstkstudy.EventProfiler as ep
import sys, getopt
import csv

# get command line options
def get_cmdline_options(argv):
    cash = float(100000.00)
    infile  = "bollinger_trade.csv"
    outfile = "bollinger_values.csv"
    
    try:
        opts, args = getopt.getopt(argv,"hc:i:o:",["cash=","infile=","outfile="])        
    except getopt.GetoptError:
        print "marketsim.py -c <cash> -i <infile> -o <outfile.csv>" 
        sys.exit(2)
    for opt, arg in opts:
        if opt == 'h':
            print "marketsim.py -c <cash> -i <infile> -o <outfile.csv>"
            print "marketsim.py -c 500000 -i orders.csv -o values.csv"
            sys.exit()
        elif opt in ('-c','--cash'):
            cash = float(arg)
        elif opt in ('-i','--infile'):
            infile = arg
        elif opt in ('-o','--ofile'):
            outfile = arg
            
    print "cmdline options: cash=%d infile=%s outfile=%s" % (cash,infile,outfile)
    return cash,infile,outfile   

#open csv file and read in all stock orders in a numpy array
def read_csvfile(infile):
    orders = []   
    f = open(infile,"rU")
    try:
        reader = csv.reader(f)
        for row in reader:
            orders.append(row[0:6])
    finally:
        f.close()
        
    sorted_orders = sorted(orders, key=lambda x: dt.datetime.strptime(x[0]+"-"+x[1]+"-"+x[2], '%Y-%m-%d'))    
    return np.asarray(sorted_orders)   

#open csv file and write out all transactions
def write_csvfile(outfile,fund):
    f = open(outfile,"wb")
    try:
        writer = csv.writer(f,delimiter=',')
        for row in fund:
            writer.writerow(row)
    finally:
        f.close()
     
# read stock database from Yahoo and return data structure
def read_stock_database(begin,end,ls_symbols):
    print "read_stock_database"
    dt_begin = dt.datetime(int(begin[0]),int(begin[1]),int(begin[2]))
    dt_end   = dt.datetime(int(end[0]),int(end[1]),int(end[2])) + dt.timedelta(days=1)

    ldt_timestamps = du.getNYSEdays(dt_begin, dt_end, dt.timedelta(hours=16))    
    
    dataobj = da.DataAccess('Yahoo', cachestalltime=0)
    ls_keys = ['open', 'high', 'low', 'close', 'volume', 'actual_close']
    ldf_data = dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)   
    d_data = dict(zip(ls_keys, ldf_data))
   
    for s_key in ls_keys:
        d_data[s_key] = d_data[s_key].fillna(method='ffill')
        d_data[s_key] = d_data[s_key].fillna(method='bfill')
        d_data[s_key] = d_data[s_key].fillna(1.0)    
     
    return ldt_timestamps, d_data   

# execute stock order
def execute_order(portfolio,df_close,i,timestamp,np_orders):    
    for order in np_orders:
        order_date  = dt.date(int(order[0]),int(order[1]),int(order[2]))
        order_stock = str(order[3]).upper()
        order_type  = str(order[4]).upper()
        order_quantity = float(order[5])
        
        if timestamp.date() == order_date:
            order_price = df_close[order_stock].ix[df_close.index[i]]
            if order_type == "BUY":               
                portfolio["cash"] -= float(order_quantity * order_price)
                try:
                    portfolio[order_stock] += order_quantity
                except KeyError:
                    portfolio[order_stock] = order_quantity
                print "%s Buying %.0f shares of %s at %0.2f | cash=%0.2f" % (order_date,order_quantity,order_stock,order_price,portfolio["cash"])
            elif order_type == "SELL":
                portfolio["cash"] += float(order_quantity * order_price)
                try:
                    portfolio[order_stock] -= order_quantity
                except KeyError:
                    portfolio[order_stock] = -order_quantity
                print "%s Selling %.0f shares of %s at %0.2f | cash=%0.2f" % (order_date,order_quantity,order_stock,order_price,portfolio["cash"])
    return portfolio

# calculate daily fund value and return it
def calculate_daily_fund_value(portfolio,df_close,i,date):    
    total = float(0.0)
    for stock in portfolio.keys():
        if stock == "cash":
            total += float(portfolio[stock])
        else:
            total += float(portfolio[stock]) * float(df_close[stock].ix[df_close.index[i]])
    
    row = [date.year, date.month, date.day, total]
    return row
                
# process stock orders
def process_stock_orders(ls_symbols, ldt_timestamps, d_data, cash, np_orders):
    print "process_stock_orders"    

    # initialize portfolio and fund
    portfolio = { "cash" : cash }
    fund = []
        
    #df_close = d_data['actual_close']
    df_close = d_data['close']    # close = adjusted close

    # Time stamps for the event range
    for i in range(0, len(df_close.index)):
        portfolio = execute_order(portfolio,df_close,i,ldt_timestamps[i],np_orders)                   
        row = calculate_daily_fund_value(portfolio,df_close,i,ldt_timestamps[i])
        fund.append(row)
    return portfolio,fund

# normalize prices
def normalize_data(prices):
    return prices / prices[0, :]

# given an array of prices, compute daily return for all stocks
def daily_return(prices):
    return tsu.returnize0(prices)

# given daily return and allocations, compute average daily return for portfolio
def avg_daily_return(daily_rets):
    avg = daily_rets.mean()
    return avg

# given an array of prices, compute standard deviation of portfolio
def std_dev(daily_rets):
    std = daily_rets.std()
    return std

def sharpe_ratio(avg_daily_rets, std_dev_tp):
    k = math.sqrt(252) # for daily returns (assume 252)
    sharpe = k * avg_daily_rets / std_dev_tp
    return sharpe

def cumulative_return(na_rets):
    cumul = float(1 + np.subtract(na_rets[-1], na_rets[0]))
    return cumul

def calc_stats(begin, end, na_price):        
    dt_begin = dt.datetime(int(begin[0]),int(begin[1]),int(begin[2])) 
    dt_end   = dt.datetime(int(end[0]),int(end[1]),int(end[2]))
    
    # normalize prices
    na_normalized_price = normalize_data(na_price) 
 
    # calculate daily return
    na_rets = na_normalized_price.copy()
    na_daily_rets = daily_return(na_rets)
        
    # average daily return
    avg_daily_rets = avg_daily_return(na_daily_rets)
    
    # compute standard deviation
    std_dev_tp = std_dev(na_daily_rets)
    
    # compute sharpe ratio
    sharpe_ratio_tp = sharpe_ratio(avg_daily_rets,std_dev_tp)
    
    #compute cumulative return
    cumul_return_tp = cumulative_return(na_normalized_price)
    
    # print out status
    print
    print "Start Date:",dt_begin,"to",dt_end
    print "Sharpe Ratio:", sharpe_ratio_tp
    print "Total Return of Fund:", cumul_return_tp
    print "Standard Deviation:  ", std_dev_tp 
    print "Average Daily Return:", avg_daily_rets
    
    
# main routine    
def main(argv):
    print "marketsim.py main"
    
    # get command line parameters
    cash,infile,outfile = get_cmdline_options(argv)
    
    # read orders csvfile into a numpy array and get list of stocks traded
    np_orders = read_csvfile(infile)
    ls_symbols = set(list(np_orders[:,3]))

    # determine the earliest and latest begin dates
    begin = np_orders[0][0:3]
    end   = np_orders[-1][0:3]

    # read stock database from Yahoo
    ldt_timestamps, d_data = read_stock_database(begin,end,ls_symbols)
           
    # loop for all NYSE stock days earliest to latest
    portfolio, fund = process_stock_orders(ls_symbols, ldt_timestamps, d_data, cash, np_orders)

    # calculate stats
    na_fund = np.array(fund)
    trading_days = na_fund.shape[0]
    na_price = na_fund[:,3].reshape(trading_days,1)
    calc_stats(begin, end, na_price)
    
    # write out csvfile
    write_csvfile(outfile,fund)
    
    print portfolio
    print "marketsim.py done"
    
if __name__ == '__main__':
    main(sys.argv[1:])