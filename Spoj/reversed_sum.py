n=input()
while n>0:
	n-=1
	n1,n2=raw_input().split()
	n1=int(n1[::-1])
	n2=int(n2[::-1])
	r=n1+n2
	r=str(r)
	r=r[::-1]
	print int(r)
	
	
	
