import bisect
from bisect import bisect_left
from bisect import bisect_right
def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]
    raise ValueError
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

def bins(a,k,hi,lo):
    if hi<lo:
        return None
    else:
        mid=(hi+lo)/2;
        if a[mid] > k:
            return bins(a,k,mid,lo)
        else:
            if a[mid]==k:
                return mid
            else:
                if a[mid] < k:
                    if hi-lo>1:
                        return bins(a,k,hi,mid)
                    else:
                        return lo

ar=[1,5,9,8,36,6,45,789,56,2]
ar.sort()
print ar,ar[bins(ar,789,len(ar),0)]
