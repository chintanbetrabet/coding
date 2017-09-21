import time
import bisect
n=int(raw_input())
A=map(int,raw_input().split(" "))
p,q=map(int,raw_input().split(" "))
mint=(0,0)
'''t1=time.clock()
for x in range(p,q+1):
    if time.clock()-t1<1:
        mini=(11234567890,11234567890)
        for y in A:
            temp=((abs(y-x),x))
            if(temp<mini):
                mini=temp    
        
        if(mint[0]<mini[0]):
            mint=mini
        if(mint[0]==mini[0]):
            if(mini<mint):
                mint=mini
    else :
        global tle
        tle=1
        break
    
if tle==1:
    print "TLE"
print mint[1]
'''
lis=[]
A.sort()
for i in range(len(A)-1):
    if(A[i]+A[i+1]<=2*q):
        lis.append(((A[i+1]-A[i])/2,(A[i+1]+A[i])/2))
    else:
        break
minv=min(lis)
print minv

