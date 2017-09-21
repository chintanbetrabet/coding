def fac(n):
	if n < 1:
		return 1;
	return n*fac(n-1)
t=raw_input()
t=int(t)
for i in range(0,t):
    x=raw_input()
    x=int(x)
    print fac(x)
