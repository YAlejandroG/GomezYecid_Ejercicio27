import os
import numpy as np
import matplotlib.pyplot as plt

implicit1 = np.loadtxt("implicit1.dat")
implicit2 = np.loadtxt("implicit0.1.dat")
implicit3 = np.loadtxt("implicit0.01.dat")
explicit1 = np.loadtxt("explicit1.dat")
explicit2 = np.loadtxt("explicit0.1.dat")
explicit3 = np.loadtxt("explicit0.01.dat")

plt.figure(figsize=(15,4))

plt.subplot(1,2,1)
x = implicit1[:,0]
y = implicit1[:,1]
plt.plot(x,y,label='dt=10')
x = implicit2[:,0]
y = implicit2[:,1]
plt.plot(x,y,label='dt=1')
x = implicit3[:,0]
y = implicit3[:,1]
plt.plot(x,y,label='dt=0.1')
plt.legend()
plt.xlabel('t')
plt.ylabel('y(t)')
plt.title('Implicit Scheme')

plt.subplot(1,2,2)
x = explicit1[:,0]
y = explicit1[:,1]
plt.plot(x,y,label='dt=10')
x = explicit2[:,0]
y = explicit2[:,1]
plt.plot(x,y,label='dt=1')
x = explicit3[:,0]
y = explicit3[:,1]
plt.plot(x,y,label='dt=0.1')
plt.legend()
plt.xlabel('t')
plt.ylabel('y(t)')
plt.title('Explicit Scheme')

plt.savefig("primergrado.png")