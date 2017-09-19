t=input()
while t>0:
	t-=1
	n=input()
	l=map(int,raw_input().split())
	l.sort()
	l=l[::-1]
	print l[n/2]
	l1=[]
	lp=0
	rp=2*n-1
	
	while rp>lp:
		l1.append(l[lp])
		lp+=1
		if lp<=rp:
			l1.append(l[rp])
			rp-=1
	for x in l1:
		print x,
	print
