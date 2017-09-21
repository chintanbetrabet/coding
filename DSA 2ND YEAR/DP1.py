import sys


def tn(n,a,b):
    if(n==1):
        return a
    else :
        if n==2:
            return b;
        else:
            tn1=tn(n-1,a,b)
            return tn1**2+tn(n-2,a,b);


a,b,n = map(int,sys.stdin.readline().split())
print tn(n,a,b)

