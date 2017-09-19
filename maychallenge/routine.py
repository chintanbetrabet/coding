t=input()
while t>0:
	t-=1
	day=raw_input()
	s=1
	c=0
	e=0
	val=True
	for x in day:
		if x=='C':
			s=0
			c=1
			e=0
		elif x=='E':
			if c==0 or e==1:
		#		print "false at E"
				val=False
			else:
				e=1
		elif x=='S':
			if c==1 and s==0:
				s=1
				e=0
				c=0
			else:
				#print "false at S"
				val=False
	if val==False:
		print "no"
	else:
		print "yes"
			
