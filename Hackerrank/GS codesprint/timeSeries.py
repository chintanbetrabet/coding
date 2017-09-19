import bisect
from bisect import bisect_left
from bisect import bisect_right

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
       return i-1
    return -1


def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
       return i
    return -1

n,q=map(int,raw_input().strip().split())
times=map(int,raw_input().strip().split())
prices=map(int,raw_input().strip().split())
Rmaxarray=[-1 for i in prices]
Lmaxarray=[-1 for i in prices]
tp=[[times[i],prices[i]] for i in range(len(prices))]
tp.sort()
times=[]
prices=[]
for i in range(n):
	times.append(tp[i][0])
	prices.append(tp[i][1])


Rmaxarray[0]=prices[0]
Lmaxarray[n-1]=prices[n-1]
for i in range(1,n):
	Rmaxarray[i]=max(prices[i],Rmaxarray[i-1])
for i in range(n-2,-1,-1):
	Lmaxarray[i]=max(prices[i],Lmaxarray[i+1])
for q1 in range(q):
	qt,num=map(int,raw_input().split())
	if qt==2:
		ind=find_le(times,num)
		if ind!=-1:
			print Lmaxarray[ind]
		else:
			print -1#," for ",qt,num
	else:
		ind=find_ge(Rmaxarray,num)
		if ind!=-1:
			print times[ind]
		else:
			print -1#," for ",qt,num
		
