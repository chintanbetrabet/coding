t=input()
t1=0
while t1<t:
	t1+=1
	st,fr=map(int,raw_input().split())
	l=map(int,raw_input().split())
	l.sort()
	l=l[::-1]
	avail=0
	i=0
	print "Scenario #%s:"%t1
	while i< fr:
		
		avail+=l[i]
		i+=1
		if avail>=st:
			break
	if avail >= st:
		print i
	else:
		print "impossible"
	print
