#!/usr/bin/env python
# coding: utf-8

# In[6]:


import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt('./my_file.txt', dtype=None)

for hist in data:
    plt.plot(hist)
    
plt.show()


# In[ ]:




