def count4(n):
	c=0
	while(n>0):
		if n%10 == 4:
			c+=1
		n/=10
	return c
t=input()
while (t > 0):
	t-=1
	n=input()
	print count4(n)
