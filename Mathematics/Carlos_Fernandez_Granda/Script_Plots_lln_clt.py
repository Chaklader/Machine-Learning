"""
"""
import os.path
import math
import matplotlib.pyplot as plt
import numpy as np

plt.close("all")
plt.rcParams['xtick.major.pad']='8'
plt.rcParams['ytick.major.pad']='8'

data = np.loadtxt(".../heights_weights_aux.txt") 
heights = data[:,1]
weights = data[:,2]
np.savetxt(".../weights.txt", weights) 

#plt.hist(heights, 100)
#plt.figure
# plt.hist(heights, bins=50)
mean_height = np.mean(heights)
n_max = 500
tries = 3
res = np.zeros((tries, n_max))
for i in range(tries):
  samp_mean_aux = 0
  for n in range(1,n_max+1):
    random_ind = np.random.choice(heights.size,1, replace=False)
    samp_mean_aux = samp_mean_aux + heights[random_ind]
    res[i,n-1] = samp_mean_aux/n
color_array = ['orange', 'blue', 'darkviolet']
m = np.mean(heights)
plt.figure(i, figsize=(14, 7))
ax = plt.subplot(111)    
ax.spines["top"].set_visible(False)    
ax.spines["bottom"].set_visible(False)    
ax.spines["right"].set_visible(False)    
plt.ylabel("Height (inches)", fontsize=18)  
plt.xlabel("n", fontsize=20)  
plt.plot(np.array([0,n_max-1]), np.array([m,m]) , color = 'red', lw=2, 
           label ='True mean')
for i in range(tries):
  #ax.set_ylim([66, 70])
  plt.plot(range(1,n_max+1),res[i],color=color_array[i], lw=2) #, label='Sample mean')  
  # plt.savefig('lln_' + str(i) + '.pdf')
plt.legend(fontsize=20)
#plt.savefig('lln_' + str(i) + '.pdf')  
plt.savefig('lln.pdf')  
  
s = np.std(heights)

def gaussian(x, mu, sig):
    return np.exp(-np.power(x - mu, 2.) / (2 * np.power(sig, 2.))) / sig / np.sqrt(2 * np.pi)

clt_n_val = np.array([50, 100, 500, 1000])
n_samples = 1000
res_clt = np.zeros((clt_n_val.size, n_samples))
n_plot = 600
for i_clt_n in range(clt_n_val.size):
  clt_n = clt_n_val[i_clt_n]
  for i in range(n_samples):
    random_ind = np.random.choice(heights.size,clt_n, replace=False)
    res_clt[i_clt_n,i] = np.mean(heights[random_ind])
  plt.figure(tries + i_clt_n, figsize=(15, 9))  
  ax = plt.subplot(111)    
  ax.spines["top"].set_visible(False)    
  ax.spines["right"].set_visible(False)    
  ax.get_xaxis().tick_bottom()  
  ax.get_yaxis().tick_left()  
  plt.xticks(fontsize=22) 
  plt.yticks(fontsize=22) 
  plt.xlabel("Height (inches)", fontsize=20)  
  plt.hist(res_clt[i_clt_n,:],50,normed=True,edgecolor = "none", color="skyblue", label='Sample mean')
  plt.plot(np.linspace(67, 69, n_plot),gaussian(np.linspace(67, 69, n_plot), m, s/np.sqrt(clt_n)), color="darkred", lw=2, 
           label="CLT prediction")
  yticks = ax.yaxis.get_major_ticks()
  yticks[0].label1.set_visible(False)
#        xticks[-1].label1.set_visible(False)
  plt.savefig('clt_' + str(i_clt_n) + '.pdf')
plt.legend(fontsize=24)
plt.savefig('clt_' + str(i_clt_n) + '.pdf')

plt.figure(tries + clt_n_val.size, figsize=(12, 9))  
ax = plt.subplot(111)    
ax.spines["top"].set_visible(False)    
ax.spines["right"].set_visible(False)    
ax.get_xaxis().tick_bottom()  
ax.get_yaxis().tick_left() 
yticks = ax.yaxis.get_major_ticks()
yticks[0].label1.set_visible(False) 
plt.xticks(fontsize=22) 
plt.yticks(fontsize=22) 
plt.xlabel("Height (inches)", fontsize=22)  
plt.hist(heights,100,normed=True,edgecolor = "none", color="green")
plt.savefig('dist.pdf')

  
