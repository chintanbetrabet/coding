# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
def floor(v):
    return long(v)


n=int(raw_input())
vals=map(int,raw_input().split(" "))
minv=0
divVal=2
p=0
for i in range(1,n+1):
    insv=2*p-vals[i-1]
    #print str(i)+"  "+str(vals[i-1])+" "+str(i-1)+" "+str(n)
    p=insv
    insv=insv/divVal
    divVal=divVal*2
    if floor(insv) < minv:
        minv=floor(insv)
print minv;
    
    
