def long_sub(a,b):
	
	dp=[ [0 for i in range(len(a))] for j in range(len(b))]
	for i in range(len(a)):
		if b[0] == a[i]:
			dp[0][i]=1
			for j in range(i,len(a)):
				dp[0][j]=1
			break;
	
	for i in range(len(b)):
		if a[0]==b[i]:
			dp[i][0]=1
			for j in range(i,len(b)):
				dp[j][0]=1
			break;
	
	for i in range(1,len(b)):
		for j in range(1,len(a)):
			if b[i]==a[j]:
				v1=dp[i-1][j-1]+1
				dp[i][j]=max(v1,dp[i][j-1])

			else:
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])
	
	print dp[len(b)-1][len(a)-1]

#t=input()
t=1
while t>0:
    t-=1
    #m,n=raw_input().strip().split()
    a=raw_input().strip()
    b=raw_input().strip()
    long_sub(a,b)
			
