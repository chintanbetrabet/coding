# Enter your code here. Read input from STDIN. Print output to STDOUT
from bisect import bisect_right
def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1],i-1
    return -1
n,k=map(int,raw_input().split(' '))
l=map(int,raw_input().split(' '))
ones=[]
for i in range(n):
    if l[i]==1:
        ones.append(i)
noelec=0
i=0
fl=1
last=-1
while i<n:
    #print "i",i," search from :",i," tp ",min(i+k+1,n),l[i:min(i+k+1,n)]
    
    next_pole,ind=find_le(ones,i+k)
    
    #print next_pole
    while next_pole==last:
        next_pole,ind=find_le(ones,ones[ind-1]+k)
        ind-=1
        print ind
    last=next_pole
    noelec+=1
    i=next_pole+k

    
if fl==0:
    print -1
else:
    print noelec
