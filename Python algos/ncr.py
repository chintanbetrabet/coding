import sys
import bisect
sys.setrecursionlimit(100000)


def ncr(n,r,nlook):
    return nlook[n]/(nlook[n-r]*nlook[r])
            
def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect.bisect_right(a, x)
    if i:
        return i-1
    raise ValueError    

fact=[1]
n=100
for i in range(1,n):
    print i
    fact.append(i*fact[i-1])
print ncr(10,2,fact)

'''
t=input()
while t>0:
    t-=1
    n,k,x=map(int,raw_input().strip().split())
    l=map(int,raw_input().strip().split())
    nclook=[0 for i in range(n+1)]
    for i in range(k-1):
        nclook[i]=0
    nclook[k-1]=1
    l.sort()
    s=0
    for i in range(len(l)):
        
        d=find_le(l,l[i]+x)
        print i,d#l[i],l[d]
        if d-i >=k-1:
            s+=ncr(d-i,k-1,nclook)%1000000007
        print ncr(d-i,k-1,nclook)%1000000007
            #print i,d,l[i],l[d]
            
    print int(s)
'''
