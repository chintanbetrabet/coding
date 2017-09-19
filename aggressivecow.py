from bisect import bisect_right
from bisect import bisect_left
def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1]
    return -1
    
def find_ge(ar, n,lo,hi):
    if hi <lo:
        return -1
    mid=(hi+lo)/2
    if hi - lo ==1:
		if ar[lo] > n:
			return ar[lo]
		***************************************if
    if ar[mid] > n:
	
        return bin_search(ar,n,lo,mid)
    else:
        if ar[mid] < n:
            return bin_search(ar,n,mid,hi)
        else:
            return mid
    return -1
def assign(n,cows,stalls,min_dis):
	 assigned=1
	 last_assigned=stalls[0]
	 last_lis=[stalls[0]]
	 while assigned <= cows and last_assigned <n:
		 last_assigned=find_ge(stalls,last_assigned+min_dis)
		 
		 if last_assigned !=-1:
			 last_lis.append(last_assigned)
			 assigned+=1
		 else:
			 #print "only assigned ",assigned
			 return False
	 if assigned==cows:
		 	 return True
	 return False
t=input()
while t>0:
	t-=1
	n,c=map(int,raw_input().split())	
	stalls=[]
	for x in range(n):
		stalls.append(input())
	stalls.sort()
	hi=10**9
	lo=0
	mid=(hi+lo)/2
	while True:
		mid=(hi+lo)/2
		#print mid,hi,lo
		
		if assign(n,c,stalls,mid):
			lo=mid
			print mid
			break
		else:
			hi=mid
		
				
		 
		 
	 
	 
	 
