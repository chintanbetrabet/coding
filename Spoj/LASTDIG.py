n=input()
#print n
while n>0:
	#print n
	n-=1
	
	a,b=map(int,raw_input().split())
	if a==0:
		print 0
	elif b==0:
		print 1
		
	else:
		remlis=[]
		for i in range(1,11):
			dig=pow(a,i)%10
			if dig in remlis:
				break
			remlis.append(dig)
	
		print remlis[(b)%len(remlis)-1]
	#print n
