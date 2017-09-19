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
print t
for x in range(t):
	n=random.randrange(800,1000)
	n1=random.randrange(80,100)
	n2=random.randrange(80,100)
	n3=random.randrange(80,100)
	n1=10
	n2=10
	n3=10
	upper=200
	perm=np.random.permutation([i for i in range(1,upper)])
	print n1,n2,n3
	for i in perm[0:n1]:
		print i,
	print
	perm=np.random.permutation([i for i in range(1,upper)])
	for i in perm[0:n2]:
		print i,
	print	
	perm=np.random.permutation([i for i in range(1,upper)])
	for i in perm[0:n3]:
		print i,
	
	print 
	
