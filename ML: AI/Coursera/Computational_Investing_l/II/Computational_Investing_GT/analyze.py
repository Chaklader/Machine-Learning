'''
File: Analyze.py
Class: Computational Investing Class - Georgia Tech
Author: Boris Litinsky
Date: 10/16/2014
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
import sys
import csv
import matplotlib.pyplot as plt

print "Pandas Version", pd.__version__

# get command line options
def get_cmdline_options():
    try:
        infile = sys.argv[2]
    except:
        infile = "values.csv"
        
    try:
        benchmark = sys.argv[3]
    except:
        benchmark = "\$SPX"

    print "cmdline options: infile=%s benchmark=%s" % (infile,benchmark)
    return infile,benchmark   

#open csv file and read in all stock orders in a numpy array
def read_csvfile(infile):
    values = []   
    f = open(infile,"rU")
    try:
        reader = csv.reader(f)
        for row in reader:
            values.append(row[0:4])
    finally:
        f.close()
    return np.asarray(values)   

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
    cumul = 1 + np.subtract(na_rets[-1], na_rets[0])
    return cumul
  
# read stock database from Yahoo and return data structure
def read_stock_database(begin,end,ls_symbols):
    print "read_stock_database"
    dt_begin = dt.datetime(int(begin[0]),int(begin[1]),int(begin[2])) - dt.timedelta(days=3)
    dt_end   = dt.datetime(int(end[0]),int(end[1]),int(end[2])) + dt.timedelta(days=1)

    ldt_timestamps = du.getNYSEdays(dt_begin, dt_end, dt.timedelta(hours=16))    
    
    dataobj = da.DataAccess('Yahoo')
    ls_keys = ['open', 'high', 'low', 'close', 'volume', 'actual_close']
    ldf_data = dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)
    d_data = dict(zip(ls_keys, ldf_data))

    for s_key in ls_keys:
        d_data[s_key] = d_data[s_key].fillna(method='ffill')
        d_data[s_key] = d_data[s_key].fillna(method='bfill')
        d_data[s_key] = d_data[s_key].fillna(1.0)    
     
    return dt_begin, dt_end, ldt_timestamps, d_data   

# process benchmark
def process_benchmark(stock, ldt_timestamps, d_data, np_fund):
    print "process_benchmark"    
    df_close = d_data['actual_close']
   
    j = 0
    for i in range(1, len(df_close.index)):
        bench_date = ldt_timestamps[i].date()
        for row in np_fund: 
           fund_date = dt.date(int(row[0]),int(row[1]),int(row[2]))
           if fund_date == bench_date:
               value = df_close[stock].ix[df_close.index[i]]
               np_fund[j][4] = value
               j +=1
               break
                   
    return np_fund

def calc_stats(prices):
    # normalize prices
    na_normalized_price = normalize_data(prices) 
 
    # calculate daily return
    na_rets = na_normalized_price.copy()
    na_daily_rets = daily_return(na_rets)
        
    # average daily return
    tp_avg_daily_rets = avg_daily_return(na_daily_rets)
    
    # compute standard deviation
    tp_std_dev = std_dev(na_daily_rets)
    
    # compute sharpe ratio
    tp_sharpe_ratio = sharpe_ratio(tp_avg_daily_rets,tp_std_dev)
    #sharpe_ratio_tp = tsu.getSharpeRatio(na_rets)
    
    #compute cumulative return
    tp_total_return = cumulative_return(na_normalized_price)
    
    return tp_sharpe_ratio, tp_total_return, tp_std_dev, tp_avg_daily_rets

def print_stats():
    # print out status
    print
    print "begin Date:",dt_begin.strftime("%B %d, %Y")
    print "End Date:  ",dt_end.strftime("%B %d, %Y")
    print "Symbols:", ls_symbols
    print "Sharpe Ratio:", sharpe_ratio_tp
    print "Volatility (stdev of daily returns):", std_dev_tp 
    print "Average Daily Return:", avg_daily_rets
    print "Cumulative Return:", cumul_return_tp
    
def main():
    print "analyze.py main"
    
    # get command line parameters
    infile,benchmark = get_cmdline_options()    
    
    # read values csvfile into a numpy array and get list of stocks traded
    np_values = read_csvfile(infile)    

    ls_symbols = [benchmark]

    # determine the earliest and latest begin dates
    begin = np_values[0][0:3]
    end   = np_values[-1][0:3]
    
    # read stock database from Yahoo
    dt_begin, dt_end, ldt_timestamps, d_data = read_stock_database(begin,end,ls_symbols)    
     
    # append benchmark to the fund
    stock = ls_symbols[0]
    np_fund = np.append(np_values,np.zeros([len(np_values),1]),1)
    np_fund = process_benchmark(stock, ldt_timestamps, d_data, np_fund)
    
    # compute statistics for total portfolio (tp)
    np_price = np_fund[:,[3]].astype(float)
    tp_sharpe_ratio, tp_total_return, tp_std_dev, tp_avg_daily_rets = calc_stats(np_price)
    
    # compute statistics for benchmark (bm)
    bm_price = np_fund[:,[4]].astype(float)
    bm_sharpe_ratio, bm_total_return, bm_std_dev, bm_avg_daily_rets = calc_stats(bm_price)
    
    # print statistics
    print "Details of the Performance of the portfolio :"

    print "Data Range : %s to %s" % (dt_begin.strftime("%B %d, %Y"), dt_end.strftime("%B %d, %Y"))
    print
    print "Sharpe Ratio of Fund  : %0.12f" % (tp_sharpe_ratio)
    print "Sharpe Ratio of %s : %0.12f" % (stock, bm_sharpe_ratio)
    print
    print "Total Return of Fund  : %0.12f" % (tp_total_return)
    print "Total Return of %s : %0.12f" % (stock,bm_total_return)
    print
    print "Standard Deviation of  Fund : %0.12f " %(tp_std_dev)
    print "Standard Deviation of %s : %0.12f" % (stock,bm_std_dev)
    print 
    print "Average Daily Return of  Fund : %0.12f" % (tp_avg_daily_rets)
    print "Average Daily Return of %s : %0.12f" % (stock, bm_avg_daily_rets)
    
    # plot graph
    #plt.clf()
    #fig = plt.figure()
    #fig.add_subplot(111)
    #plt.plot(ldt_timestamps, np_price, alpha=0.4)
    #plt.plot(ldt_timestamps, bm_price)
    #ls_names = ls_port_syms
    #ls_names.append('Portfolio')
    #plt.legend(ls_names)
    #plt.ylabel('Cumulative Returns')
    #plt.xlabel('Date')
    #fig.autofmt_xdate(rotation=45)
    #plt.savefig('tutorial3.pdf', format='pdf')
    
if __name__ == '__main__':
    main()
