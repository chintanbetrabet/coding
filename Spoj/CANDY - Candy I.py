
while True:
		n=input()
		#print "n=",n
		if n==-1:
			break
		l=[]
		t=0
		n1=n
		while n>0:
			n-=1
			s=input()
			t+=s
			l.append(s)
		if t%n1 !=0:
			print -1
		else:
		
			v=t/n1
			move=0
	
			for x in l:
				move+=abs(x-v)
			print move/2
		#n=input()
