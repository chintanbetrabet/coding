# Enter your code here. Read input from STDIN. Print output to STDOUT
from bisect import bisect_left
global ino
ino =[]
def inorder(ar,i,n):
    if 2*i+1<n:
        inorder(ar,2*i+1,n)
    
    ino.append(ar[i])
    if 2*i+2<n:
        inorder(ar,2*i+2,n)
def bin_search(ar,n,lo,hi):
    if hi <lo:
        return -1
    mid=(hi+lo)/2
    if ar[mid] > n:
        return bin_search(ar,n,lo,mid)
    else:
        if ar[mid] < n:
            return bin_search(ar,n,mid,hi)
        else:
            return mid
def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

t=input()
while t>0:
    t-=1
    n=input()
    ino=[]
    ar=map(int,raw_input().split())
    inorder(ar,0,n)
    ar.sort()
    mods=0
    nmods=0
    i=0
    while nmods<n:
        if ino[i]!=ar[i]:
            p=bin_search(ar,ino[i],0,n)
            ino[p],ino[i]=ino[i],ino[p]
            mods+=1
            nmods=0
        else:
            nmods+=1            
        i+=1
        i%=n
    print mods
