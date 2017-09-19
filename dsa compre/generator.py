import random
import numpy as np

'''
#Strings=["((a+b)/(c+d))$","(((a-b)+(c-d)*(b-c/d))+(e/f))$","b*(e+f*(e*(a+b)+c))/d$","a*((a-b+c*d)+(f+e/a+b*g))$"]
#mvalue=[4,6,6,7]
#t=[1000,10000,100000,100000]
#ti=3
#print Strings[ti]
#print t[ti]
#for i in range(t[ti]):
	v=[random.randrange(-1000,1000) for i in range(mvalue[ti])]
	for x in v:
		print x,
	print
	
'''
t=random.randrange(10,15) 
s="["
'''
for x in v:
	s+=str(x)+","
print s
'''
t=1
for x in range(t):
	n=random.randrange(800,1000)
	perm=np.random.permutation([i for i in range(1,10000)])
	print n
	for i in perm[0:n]:
		print i,
	print 
	
