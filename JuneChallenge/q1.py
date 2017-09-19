def check3sum(l):
	for i in range(len(l)):
		for j in range(i+1,len(l)):
			for k in range(j+1,len(l)):
				if l[i]+l[j]==l[k]:
					return False
	return True
		
t=input()
while t>0:
	t-=1
	n=input()
	l=[]
	for i in range(n):
		print n+i+1,
		l.append(n+i+1)
	print
	#print check3sum(l)
