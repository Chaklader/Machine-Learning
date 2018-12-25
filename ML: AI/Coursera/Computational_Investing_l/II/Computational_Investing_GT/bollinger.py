'''
File: bollinger.py
Class: Computation Investing - Georgia Tech
Author: Boris Litinsky
Date: 10/26/2014
Description: Compute Bollinger Bands
'''

import datetime as dt
import pandas as pd
import numpy as np
import math
import copy
import QSTK.qstkutil.qsdateutil as du
import QSTK.qstkutil.DataAccess as da
import QSTK.qstkutil.tsutil as tsu
import QSTK.qstkstudy.EventProfiler as ep
import matplotlib.pyplot as plt
import sys, getopt
import csv

# get command line options
def get_cmdline_options(argv):    
    begin = [2010, 1, 1]
    end = [2010, 12, 31]
    stocks = ['MSFT', 'AAPL']
    outfile = "bollinger"
    
    try:
        opts, args = getopt.getopt(argv,"hb:e:s:o:",["begin=","end=","stock=","outfile="])
        
    except getopt.GetoptError:
        print "bollinger.py -b <begin_year> -e <end_year> -s <stocks> -o <outfile.csv>" 
        sys.exit(2)
    for opt, arg in opts:
        if opt == 'h':
            print "bollinger.py -b <begin_year> -e <end_year> -s <stock_list> -o <outfile.csv>"
            print "bollinger.py -b 2011 -e 2011 -s AAPL,MSFT -o bolligner.csv"
            sys.exit()
        elif opt in ('-b','--begin'):
            begin = [int(arg), 1, 1]
        elif opt in ('-e','--end'):
            end = [int(arg), 12, 31]
        elif opt in ('-s','--stock'):
            stocks = str(arg)
            stocks = stocks.split(",")
        elif opt in ('-o','--ofile'):
            outfile = arg
    
    dt_begin = dt.datetime(int(begin[0]),int(begin[1]),int(begin[2])) 
    dt_end   = dt.datetime(int(end[0]),int(end[1]),int(end[2]))
    
    if dt_begin > dt_end:
        print "Error: begining date must be before ending date"
        sys.exit(2)
    print "cmdline options: begin=",dt_begin," end=",dt_end,"stocks=",stocks," outfile=",outfile
    return dt_begin,dt_end,stocks,outfile

#open csv file and write out all trades
def write_csvfile(outfile,data):
    f = open(outfile + ".csv","wb")
    try:
        writer = csv.writer(f,delimiter=',')
        for row in data:
            writer.writerow(row)
    finally:
        f.close()

def calc_bollinger(ls_symbols, d_data):
    print "Calculate Bollinger Bands"
    
    # Finding the event dataframe
    df_close = d_data['actual_close']

    # Time stamps for the event range
    ldt_timestamps = df_close.index

    bollinger = []    
    closing_price = {}
    rolling_mean = {}
    rolling_std = {}
    bollinger_upper = {}
    bollinger_lower = {}
    bollinger_value = {}
    
    for s_sym in ls_symbols:
        closing_price[s_sym] = df_close[s_sym]
        rolling_mean[s_sym] = pd.rolling_mean(df_close[s_sym], window=20, min_periods=1)
        rolling_std[s_sym]  = pd.rolling_std (df_close[s_sym], window=20, min_periods=1)
        bollinger_upper[s_sym] = rolling_mean[s_sym] + rolling_std[s_sym]
        bollinger_lower[s_sym] = rolling_mean[s_sym] - rolling_std[s_sym] 
        bollinger_value[s_sym] = (closing_price[s_sym] - rolling_mean[s_sym]) / rolling_std[s_sym]
 
    for i in range(1, len(ldt_timestamps)):
        for s_sym in ls_symbols:
            date = ldt_timestamps[i]
            price = df_close[s_sym].ix[ldt_timestamps[i]]
            mean  = rolling_mean[s_sym].ix[ldt_timestamps[i]]
            std   = rolling_std[s_sym].ix[ldt_timestamps[i]]
            upper = bollinger_upper[s_sym].ix[ldt_timestamps[i]]
            lower = bollinger_lower[s_sym].ix[ldt_timestamps[i]]
            value = bollinger_value[s_sym].ix[ldt_timestamps[i]]
            
            bollinger.append([date, s_sym, price, mean, std, upper, lower, value ])
            
    return bollinger

def plot(ldt_timestamps,ls_symbols,d_data):
    na_price = d_data['close'].values
    plt.clf()
    plt.plot(ldt_timestamps, na_price)
    plt.legend(ls_symbols)
    plt.ylabel('Adjusted Close')
    plt.xlabel('Date')
    plt.savefig('adjustedclose.pdf', format='pdf')    

# read stock database from Yahoo and return data structure
def read_stock_database(dt_begin,dt_end,ls_symbols):
    print "read_stock_database"
    dt_end +=dt.timedelta(days=1)

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

def main(argv):
    print "bollinger.py main routine\n"
    dt_begin, dt_end, ls_symbols, outfile = get_cmdline_options(argv)
    ldt_timestamps, d_data = read_stock_database(dt_begin, dt_end,ls_symbols)
  
    bollinger = calc_bollinger(ls_symbols, d_data)
    write_csvfile(outfile,bollinger)
    plot(ldt_timestamps, ls_symbols, d_data)
    
    #print bollinger
    print "bollinger.py main done\n"
    

if __name__ == '__main__':
    main(sys.argv[1:])