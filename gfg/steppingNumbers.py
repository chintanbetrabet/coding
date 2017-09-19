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
        return i-1
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return i-1
    raise ValueError

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return i
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return i
    raise ValueError


steps=[]
def make_steps(v,l):
	if l>6:
		return
	else:
		d=v%10
		if d>0 and d < 9:
			s=str(v)
			s1=s+str(d+1)
			s1=int(s1)
			if s1 not in steps:
				steps.append(s1)
				make_steps(s1,l+1)
			s2=s+str(d-1)
			s2=int(s2)
			if True or s2 not in steps:
				steps.append(s2)
				make_steps(s2,l+1)
		elif d==0:
			s1=v*10+1
			if True or s1 not in steps:
				steps.append(s1)
				make_steps(s1,l+1)
		else:
			s1=v*10+8
			if True or s1 not in steps:
				steps.append(s1)
				make_steps(s1,l+1)
start=[i for i in range(1,10)]
steps.append(0)
for x in start:
	steps.append(x)
	make_steps(x,2)
steps.sort()
#print steps,len(steps)
'''
for i in range(1000001):
	s=str(i)
	f=1
	#print s,len(s)
	for j in range(1,len(s)):
		if abs(int(s[j])-int(s[j-1])) !=1:
			f=0
			break
	if f==1:
		steps.append(i)
print steps
'''
t=int(input())	

while t >0:
	t-=1
	m,n=map(int,raw_input().split())
	st=find_ge(steps,m)
	end=find_le(steps,n)
	#print st,steps[st],"         ",end,steps[end]
	print (end-st+1)
	#print num
	

