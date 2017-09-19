t=input()
for x1 in range(t):
	s=raw_input()
	c=0
	e=0
	f=0
	val=True
	for x in s:
		if x=='C':
			c=1
			if e>0 or s > 0:
				val=False
				break
		if x=='E':
			e=1
			if s>0:
				print 
				val=False
				break
		if x=='S':
			s=1
	if val==True:
		print "yes"
	else:
		print "no"
