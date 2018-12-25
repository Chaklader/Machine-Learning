'''
(c) 2011, 2012 Georgia Tech Research Corporation
This source code is released under the New BSD license.  Please see
http://wiki.quantsoftware.org/index.php?title=QSTK_License
for license details.

Created on January, 24, 2013

@author: Sourabh Bajaj
@contact: sourabhbajaj@gatech.edu
@summary: Example tutorial code.
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

print "Pandas Version", pd.__version__

# normalize prices
def normalize_data(prices):
    return prices / prices[0, :]

# given an array of prices, compute daily return for all stocks
def daily_return(prices):
    return tsu.returnize0(prices)

# given daily return and allocations, compute average daily return for portfolio
def avg_daily_return(daily_rets, allocations):
    avg = daily_rets.mean(axis=0)
    w = np.array(allocations)
    avg_portfolio = np.dot(avg,w.T)
    #avg_portfolio = sum([avg[i] * allocations[i] for i in range(len(avg))])
    return avg_portfolio

# given an array of prices, compute standard deviation of portfolio
def std_dev(daily_rets, allocations):
    std = daily_rets.std(axis=0)
    corr_matrix = np.corrcoef(daily_rets,rowvar=0) 
    w = np.array(allocations)
    #print "corr_matrix"
    #print corr_matrix
    #print "w=",w       
    #std_portfolio = np.sqrt(w.T.dot(corr_matrix).dot(w))
    std_portfolio = sum([std[i] * allocations[i] for i in range(len(std))])
    return std_portfolio

def sharpe_ratio(avg_daily_rets, std_dev_tp):
    k = math.sqrt(250) # for daily returns
    sharpe = k * avg_daily_rets / std_dev_tp
    return sharpe

def cumulative_return(na_rets, allocations):
    cumul = np.subtract(na_rets[-1], na_rets[0])
    cumul_portfolio = 1 + sum([cumul[i] * allocations[i] for i in range(len(cumul))])
    return cumul_portfolio
    
def simulate(startdate, enddate, ls_symbols, allocations):
    # Start and End date of the charts
    dt_start = dt.datetime(startdate[0], startdate[1], startdate[2])
    dt_end   = dt.datetime(enddate[0],   enddate[1],   enddate[2])
    
    # We need closing prices so the timestamp should be hours=16.
    dt_timeofday = dt.timedelta(hours=16)    

    # Start and End date of the charts
    ldt_timestamps = du.getNYSEdays(dt_start, dt_end, dt_timeofday)
   
    # Creating an object of the dataaccess class with Yahoo as the source.
    c_dataobj = da.DataAccess('Yahoo')
    
    # Keys to be read from the data, it is good to read everything in one go.
    ls_keys = ['open', 'high', 'low', 'close', 'volume', 'actual_close']    
    
    # Reading the data, now d_data is a dictionary with the keys above.
    # Timestamps and symbols are the ones that were specified before.
    ldf_data = c_dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)
    d_data = dict(zip(ls_keys, ldf_data))    
   
    # Filling the data for NAN
    for s_key in ls_keys:
        d_data[s_key] = d_data[s_key].fillna(method='ffill')
        d_data[s_key] = d_data[s_key].fillna(method='bfill')
        d_data[s_key] = d_data[s_key].fillna(1.0)

    # Getting the numpy ndarray of close prices.
    na_price = d_data['close'].values  
    #print "na price"
    #print na_price
    
    # normalize prices
    na_normalized_price = normalize_data(na_price) 
 
    # calculate daily return
    na_rets = na_normalized_price.copy()
    daily_rets = daily_return(na_rets)
    
    # calculate daily total portfolio return
    w = np.array(allocations)
    daily_rets_tp = np.dot(daily_rets, w.T)
    
    # average daily return
    avg_daily_rets = avg_daily_return(daily_rets, allocations)
    
    # compute standard deviation
    std_dev_tp = std_dev(daily_rets, allocations)
    
    # compute sharpe ratio
    sharpe_ratio_tp = sharpe_ratio(avg_daily_rets,std_dev_tp)
    #sharpe_ratio_tp = tsu.getSharpeRatio(na_rets)
    
    #compute cumulative return
    cumul_return_tp = cumulative_return(na_normalized_price, allocations)
    
    # print out status
    print
    print "Start Date:",dt_start.strftime("%B %d, %Y")
    print "End Date:  ",dt_end.strftime("%B %d, %Y")
    print "Symbols:", ls_symbols
    print "Optimal Allocations:", allocations
    print "Sharpe Ratio:", sharpe_ratio_tp
    print "Volatility (stdev of daily returns):", std_dev_tp 
    print "Average Daily Return:", avg_daily_rets
    print "Cumulative Return:", cumul_return_tp
    
    
def main():
    simulate([2011, 1, 1], [2011, 12, 31], ["AAPL", "GLD", "GOOG", "XOM"], [ 0.4, 0.4, 0.0, 0.2 ])
    simulate([2010, 1, 1], [2010, 12, 31], ["AXP","HPQ","IBM","HNZ"], [ 0.0, 0.0, 0.0, 1.0 ])

    
if __name__ == '__main__':
    main()
