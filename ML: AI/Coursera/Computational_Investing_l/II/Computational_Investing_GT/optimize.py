'''
File:   optimize.py
Class:  Market Simulator for Computational Investing Class - Georgia Tech
Author: Boris Litinsky
Date:   10/15/2014
Description: Compute optimal portfolio allocation
'''

# QSTK Imports
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.tsutil as tsu
import QSTK.qstkutil.DataAccess as da

# Third Party Imports
import datetime as dt
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import math
import itertools as it
import sys, getopt
import csv

print "Pandas Version", pd.__version__

# get command line options
def get_cmdline_options(argv):    
    begin = [2012, 1, 1]
    end   = [2012, 12, 31]
    #stocks = ['BRCM','TXN','IBM','HNZ']
    stocks = ['AAPL','GOOG', 'AMZN']
    
    try:
        opts, args = getopt.getopt(argv,"hb:e:s:",["begin=","end=","stock="])
        
    except getopt.GetoptError:
        print "optimize.py -b <begin_year> -e <end_year> -s <stocks>" 
        sys.exit(2)
    for opt, arg in opts:
        if opt == 'h':
            print "optimize.py -b <begin_year> -e <end_year> -s <stock_list> -o <outfile.csv>"
            print "optimize.py -b 2011 -e 2011 -s AAPL,MSFT"
            sys.exit()
        elif opt in ('-b','--begin'):
            begin = [int(arg), 1, 1]
        elif opt in ('-e','--end'):
            end = [int(arg), 12, 31]
        elif opt in ('-s','--stock'):
            stocks = str(arg)
            stocks = stocks.split(",")
    
    dt_begin = dt.datetime(int(begin[0]),int(begin[1]),int(begin[2])) 
    dt_end   = dt.datetime(int(end[0]),int(end[1]),int(end[2]))
    
    if dt_begin > dt_end:
        print "Error: begining date must be before ending date"
        sys.exit(2)
    print "cmdline options: begin=",dt_begin," end=",dt_end,"stocks=",stocks
    return dt_begin,dt_end,stocks

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
def read_stock_database(dt_begin,dt_end,ls_symbols):
    print "read_stock_database"

    dataobj = da.DataAccess('Yahoo', cachestalltime=0)
    ldt_timestamps = du.getNYSEdays(dt_begin, dt_end, dt.timedelta(hours=16))        
    ls_keys = ['open', 'high', 'low', 'close', 'volume', 'actual_close']
    ldf_data = dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)   
    d_data = dict(zip(ls_keys, ldf_data))
   
    for s_key in ls_keys:
        d_data[s_key] = d_data[s_key].fillna(method='ffill')
        d_data[s_key] = d_data[s_key].fillna(method='bfill')
        d_data[s_key] = d_data[s_key].fillna(1.0)    
     
    return ldt_timestamps, d_data   

def simulate(dt_begin, dt_end, ls_symbols, allocation):
    
    ldt_timestamps, d_data = read_stock_database(dt_begin, dt_end, ls_symbols)
    
    # Getting the numpy ndarray of close prices.
    na_price = d_data['close'].values  
    trading_days = na_price.shape[0]

    # collapse portfolio
    w = np.array(allocation)
    na_price_tp = np.dot(na_price, w.T).reshape(trading_days,1)
    #print "na_price_tp"
    #print na_price_tp
    
    # normalize prices
    na_normalized_price = normalize_data(na_price_tp) 
    #print na_normalized_price
 
    # calculate daily return
    na_rets = na_normalized_price.copy()
    na_daily_rets = daily_return(na_rets)
        
    # average daily return
    avg_daily_rets = avg_daily_return(na_daily_rets)
    
    # compute standard deviation
    std_dev_tp = std_dev(na_daily_rets)
    
    # compute sharpe ratio
    sharpe_ratio_tp = sharpe_ratio(avg_daily_rets,std_dev_tp)
    #sharpe_ratio_tp = tsu.getSharpeRatio(na_rets)
    
    #compute cumulative return
    cumul_return_tp = cumulative_return(na_normalized_price)
    
    # print out status
    print
    print "Start Date:",dt_begin.strftime("%B %d, %Y")
    print "End Date:  ",dt_end.strftime("%B %d, %Y")
    print "Symbols:", ls_symbols
    print "Allocation:", allocation
    print "Sharpe Ratio:", sharpe_ratio_tp
    print "Volatility (stdev of daily returns):", std_dev_tp 
    print "Average Daily Return:", avg_daily_rets
    print "Cumulative Return:", cumul_return_tp
    return sharpe_ratio_tp

# compute all possible legal portfolio allocations
def calc_allocations(ls_symbols):    
    allocations = []
    vals = [x*0.1 for x in range(11)]
    combinations = it.product(vals, repeat=len(ls_symbols))
    for allocation in combinations:
        if sum(allocation) == 1.0:
            allocations.append(allocation)
    return allocations    
    
def optimize(dt_begin, dt_end, ls_symbols):
    result = []
    allocations = calc_allocations(ls_symbols)
    for allocation in allocations:
        sharpe = simulate(dt_begin, dt_end, ls_symbols, allocation)
        result.append([sharpe, allocation])               
    print result
    print "Maximum Sharpe"
    print max(result)

def main(argv):
    dt_begin, dt_end, stocks = get_cmdline_options(argv)
    optimize(dt_begin, dt_end, stocks)
                                        
    #simulate([2011, 1, 1], [2011, 12, 31], ["AAPL", "GLD", "GOOG", "XOM"], [ 0.4, 0.4, 0.0, 0.2 ])
    #simulate([2010, 1, 1], [2010, 12, 31], ["AXP","HPQ","IBM","HNZ"], [ 0.0, 0.0, 0.0, 1.0 ])
    #simulate([2011, 1, 1], [2011, 12, 31], ["BRCM","TXN","AMD","ADI"], [ 0.0, 1.0, 0.0, 0.0 ])
    #optimize([2011, 1, 1], [2011, 12, 31], ["BRCM","TXN","AMD","ADI"])
    #optimize([2010, 1, 1], [2010, 12, 31], ["BRCM","TXN","IBM","HNZ"])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.1, 0.1, 0.0, 0.8])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.3, 0.0, 0.7, 0.0])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.1, 0.1, 0.6, 0.2])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.4, 0.4, 0.0, 0.2])

if __name__ == '__main__':
    main(sys.argv[1:])
