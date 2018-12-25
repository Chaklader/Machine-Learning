'''
File: find_events.py
Class: Computation Investing - Georgia Tech
Author: Boris Litinsky
Date:  10/1/2014
Description: Find Financial Events
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

"""
Accepts a list of symbols along with start and end date
Returns the Event Matrix which is a pandas Datamatrix
Event matrix has the following structure :
    |IBM |GOOG|XOM |MSFT| GS | JP |
(d1)|nan |nan | 1  |nan |nan | 1  |
(d2)|nan | 1  |nan |nan |nan |nan |
(d3)| 1  |nan | 1  |nan | 1  |nan |
(d4)|nan |  1 |nan | 1  |nan |nan |
...................................
...................................
Also, d1 = start date
nan = no information about any event.
1 = status bit(positively confirms the event occurence)
"""

# get command line options
def get_cmdline_options(argv):    
    begin = [2012, 1, 1]
    end   = [2013, 12, 31]
    stocks = 'sp5002012'
    outfile = "events"
    
    try:
        opts, args = getopt.getopt(argv,"hb:e:s:o:",["begin=","end=","stock=","ofile="])
        
    except getopt.GetoptError:
        print "find_events.py -b <begin_year> -e <end_year> -s <stocks> -o <outfile.csv>" 
        sys.exit(2)
    for opt, arg in opts:
        if opt == 'h':
            print "find_events.py -b <begin_year> -e <end_year> -s <stock_list> -o <outfile.csv>"
            print "find_events.py -b 2011 -e 2011 -s sp5002012 -o find_events.csv"
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
        
def find_events(ls_symbols, d_data):
    print "find_events"
    df_close = d_data['actual_close']
    ts_market = df_close['SPY']

    # Creating an empty dataframe
    df_events = copy.deepcopy(df_close)
    df_events = df_events * np.NAN

    # Time stamps for the event range
    ldt_timestamps = df_close.index
    events = []

    for s_sym in ls_symbols:
        for i in range(1, len(ldt_timestamps)):
            # Calculating the returns for this timestamp
            f_symprice_today = df_close[s_sym].ix[ldt_timestamps[i]]
            f_symprice_yest = df_close[s_sym].ix[ldt_timestamps[i - 1]]
            f_marketprice_today = ts_market.ix[ldt_timestamps[i]]
            f_marketprice_yest = ts_market.ix[ldt_timestamps[i - 1]]
            f_symreturn_today = (f_symprice_today / f_symprice_yest) - 1
            f_marketreturn_today = (f_marketprice_today / f_marketprice_yest) - 1

            # Event is found if the symbol is down more then 3% while the
            # market is up more then 2%
            #if f_symreturn_today <= -0.03 and f_marketreturn_today >= 0.02:
            #    df_events[s_sym].ix[ldt_timestamps[i]] = 1
            if f_symprice_today < 20.00 and f_symprice_yest >= 20.00:
            #if (f_symprice_today / f_symprice_yest ) < 0.80:
                events.append([ldt_timestamps[i],s_sym,f_symprice_today])
                df_events[s_sym].ix[ldt_timestamps[i]] = 1

    return df_events, events

# read stock database from Yahoo and return data structure
def read_stock_database(dt_begin, dt_end, stocks):
    print "read_stock_database"

    dataobj = da.DataAccess('Yahoo', cachestalltime=0)
    ldt_timestamps = du.getNYSEdays(dt_begin, dt_end, dt.timedelta(hours=16)) 
    ls_symbols = dataobj.get_symbols_from_list(stocks)
    ls_symbols.append('SPY')
    
    ls_keys = ['open', 'high', 'low', 'close', 'volume', 'actual_close']
    ldf_data = dataobj.get_data(ldt_timestamps, ls_symbols, ls_keys)   
    d_data = dict(zip(ls_keys, ldf_data))
   
    for s_key in ls_keys:
        d_data[s_key] = d_data[s_key].fillna(method='ffill')
        d_data[s_key] = d_data[s_key].fillna(method='bfill')
        d_data[s_key] = d_data[s_key].fillna(1.0)    
     
    return ldt_timestamps, ls_symbols, d_data   
   
def main(argv):
    print "find_events.py main routine\n"
    
    dt_begin, dt_end, stocks, outfile = get_cmdline_options(argv)
    ldt_timestamps, ls_symbols, d_data = read_stock_database(dt_begin, dt_end, stocks)   

    df_events, events = find_events(ls_symbols, d_data)
    write_csvfile(outfile,events)
    
    studyfile = outfile + ".pdf"
    print "creating study in file:",studyfile
    ep.eventprofiler(df_events, d_data, i_lookback=20, i_lookforward=20,
                s_filename=studyfile, b_market_neutral=True, b_errorbars=True,
                s_market_sym='SPY')

if __name__ == '__main__':
    main(sys.argv[1:])