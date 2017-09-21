import sys
def mod(base,exp,m):
    
    if exp==0:
        return 1;
    
    else :
       if exp==1:
           return base%m           
         
       else :
           if exp%2==0 and exp!=0:
            v=mod(base,int(exp/2),m)
            return (v*v)%m;
        
           else :
               v=mod(base,int(exp/2),m)
               return (v*v*base)%m;
        
    
    
sum1=0
m=1000000007

n,k=raw_input().split(' ')
n=long(n)
k=long(k)
if k==0:
    sum1=n;
else:
    for i in range(1,n+1):
        sum1=sum1+mod(i,k,m)
sum1%=m

print sum1
