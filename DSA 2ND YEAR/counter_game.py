import sys
import math
def log2(num):
    return num != 0 and ((num & (num - 1)) == 0)

t=raw_input()
t=int(t)

for i in range(0,t):
    n=raw_input()
    n=int(n)
    count=0
    while n > 1:
        if log2(n)!=1:
            #print "power"
            n-=pow(2,int(log2(n)))
        else:
            n/=2
        count+=1
    if count%2==0:
        print "Richard"
    else:
        print "Louise"
        
        
    
