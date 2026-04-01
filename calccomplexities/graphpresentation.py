import numpy as np 
import matplotlib.pyplot as plt 

n = np.arange(1,11)

logn = np.log(n)
linear = n
square = n**2
nn = n**n
expn = np.exp(n)

plt.figure()

plt.plot(n,logn,label='log(n)')

plt.plot(n,linear,label='n')

plt.plot(n,square,label='n*2')

plt.plot(n,expn,label='e*n')

plt.plot(n,nn,label='n*n')


plt.title('Growth of Function (Log Scale)')
plt.xlabel('n')
plt.ylabel('Value(log scale)')
plt.legend()

plt.grid(True)
plt.show()