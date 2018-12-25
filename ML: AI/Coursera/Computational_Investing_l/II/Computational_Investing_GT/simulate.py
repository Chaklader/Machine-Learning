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
    
def simulate(startdate, enddate, ls_symbols, allocations):
    
    #clear the cache
    c_dataobj = da.DataAccess('Yahoo', cachestalltime=0)
    
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
    trading_days = na_price.shape[0]

    # collapse portfolio
    w = np.array(allocations)
    na_price_tp = np.dot(na_price, w.T).reshape(trading_days,1)
    print "na_price_tp"
    print na_price_tp
    
    
    
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
    print "Start Date:",dt_start.strftime("%B %d, %Y")
    print "End Date:  ",dt_end.strftime("%B %d, %Y")
    print "Symbols:", ls_symbols
    print "Optimal Allocations:", allocations
    print "Sharpe Ratio:", sharpe_ratio_tp
    print "Volatility (stdev of daily returns):", std_dev_tp 
    print "Average Daily Return:", avg_daily_rets
    print "Cumulative Return:", cumul_return_tp
    return sharpe_ratio_tp
    
def optimize(startdate, enddate, ls_symbols):
    result = []
    for i in range(11):
        for j in range(11):
            for k in range(11):
                for l in range (11):
                    if (i+j+k+l) == 10:
                        #print "i=",i,"j=",j,"k=",k,"l=",l  
                        allocation = [i*0.1, j*0.1, k*0.1, l*0.1] 
                        sharpe = simulate(startdate, enddate, ls_symbols, allocation)
                        result.append([sharpe, allocation])               
    print result
    print "Maximum Sharpe"
    print max(result)

def main():
    #simulate([2011, 1, 1], [2011, 12, 31], ["AAPL", "GLD", "GOOG", "XOM"], [ 0.4, 0.4, 0.0, 0.2 ])
    #simulate([2010, 1, 1], [2010, 12, 31], ["AXP","HPQ","IBM","HNZ"], [ 0.0, 0.0, 0.0, 1.0 ])
    #simulate([2011, 1, 1], [2011, 12, 31], ["BRCM","TXN","AMD","ADI"], [ 0.0, 1.0, 0.0, 0.0 ])
    #optimize([2011, 1, 1], [2011, 12, 31], ["BRCM","TXN","AMD","ADI"])
    optimize([2010, 1, 1], [2010, 12, 31], ["BRCM","TXN","IBM","HNZ"])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.1, 0.1, 0.0, 0.8])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.3, 0.0, 0.7, 0.0])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.1, 0.1, 0.6, 0.2])
    #simulate([2010, 1, 1], [2010, 12, 31],  ["BRCM","TXN","IBM","HNZ"], [0.4, 0.4, 0.0, 0.2])

if __name__ == '__main__':
    main()
