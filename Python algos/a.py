def bin2(a,hi,lo):
    if hi<lo:
        return None
    mid=(hi+lo)/2
    if a[mid] < a[hi] and a[mid] < a[lo]:
        return a[mid]
    if a[mid] < a[hi] and a[mid] > a[lo]:
        return bin2(a,lo,mid)
    if a[mid] > a[hi]:
        return a[hi]
        
    return bin2(a,mid,hi)
        

t=input()
while t>0:
    t-=1
    n=input()
    l=map(int,raw_input().strip().split())
    print bin2(l,n-1,0)
