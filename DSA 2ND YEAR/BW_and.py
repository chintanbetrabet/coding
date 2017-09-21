import math
import sys
t=raw_input()
t=int(t)
for x in range(0,t):
    a,b=raw_input().split(" ")
    a=int(a)
    b=int(b)
    val=a
    if b>a:
        maxlim=int(math.log(a,2))
        diff=b-a
        minlim=int(math.log(diff+1,2))
        while pow(2,minlim)<diff:
            minlim+=1
        print maxlim
        print minlim
        val=0
        for i in range(minlim,maxlim):
            val+=pow(2,i)
        
