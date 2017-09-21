def left_under(val,l,hi,lo):
    while lo<hi-1:
        
        mid=(hi+lo)/2
       # print hi,lo
        if l[mid] > val:
            hi=mid
        elif l[mid] <val :
            lo=mid
        else:
            return mid
    if l[hi]<val or l[hi]==val:
        return hi
    
    return lo
def right_over(val,l,hi,lo):
    while lo<hi-1:
        
        mid=(hi+lo)/2
      #  print hi,lo
        if l[mid] > val:
            hi=mid
        elif l[mid] <val :
            lo=mid
        else:
            return mid
    if l[lo]>val or l[lo]==val:
        return lo
    
    return hi
    
n=raw_input()
n=int(n)
l=[]
l=map(int,raw_input().split());
l.sort()
nq=raw_input()
nq=int(nq)
sum1=0
off=0
for ele in range(0,n):
    sum1+=abs(l[ele])
ql=map(int,raw_input().split())

for q in ql:
    p1=0;p2=0;
    if q>0:
        p1=left_under(-1*q+off,l,n-1,0)
        p2=right_over(0-off,l,n-1,0)
        print p1,p2,off
        off=off+q
    else :
        p1=left_under(q-off,l,n-1,0)
        p2=right_over(q-off,l,n-1,0)
        print p1,p2,off
        off=off+q
        
    
    
    


