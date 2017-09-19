t=input()
while t >0:
	t-=1
	n=raw_input()
	sumsub=0
	for i in range(len(n)):
		for j in range(i+1,len(n)+1):
			sumsub+=int(n[i:j])
	print sumsub
