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
        return a[i-1],i-1
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
        return a[i],i
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]
    raise ValueError
t=input()
while t>0:
	t-=1
	s=raw_input()
	As=[]
	Bs=[]
	Cs=[]
	for i in range(len(s)):
		
		x=s[i]
		if x=='a':
			As.append(i)
		if x=='b':
			Bs.append(i)
		if x=='c':
			Cs.append(i)
	dpA=[]
	for i in range(len(As)):
		
		v=As[i]
		print "v=",v
		closeB,bstart=find_gt(Bs,v)
		print "CB=",closeB
		closeC,cstart=find_gt(Cs,closeB)
		lastB,bend=find_lt(Bs,closeC)
		dpA.append((pow(2,i))*(pow(2,bend-bstart+1)-1)*(pow(2,len(Cs)-cstart-1)))
		print "for a:",i,"apart=",(pow(2,i)),"bpart=",(pow(2,bend-bstart)),"cpart=",(pow(2,len(Cs)-cstart-1))
	print dpA
		
		
