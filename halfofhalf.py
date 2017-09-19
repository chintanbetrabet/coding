# your code goes here
t=input()
while(t>0):
	t-=1
	s=raw_input()
	for i in range(0,len(s)/2,2):
		print s[i],
	print
