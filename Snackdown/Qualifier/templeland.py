t=input()
while t>0:
	t-=1
	n=input()
	l=map(int,raw_input().split())
	fl=True
	fl=((n%2==1) and (l[0]==1))
	for i in range(n/2+1):
		if l[i]!=i+1:
			fl=False
	for i in range(n/2+2,n):
		if l[i]!=n-i:
			fl=False
	if fl==False:
		print "no"
	else:
		print "yes"
