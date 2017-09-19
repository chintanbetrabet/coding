t=input()
while t>0:
	t-=1
	n=input()
	l1=raw_input()
	l2=raw_input()
	l1s=[]
	l2s=[]
	c=0
	flag=0
	for i in range(len(l1)):
		if l1[i]=='*' or l2[i]=='*':
			c+=1
		if l1[i]=='*' and l2[i]=='*':
			flag=1
			
	c=max(c-1+flag,0)
	print c
			
		
