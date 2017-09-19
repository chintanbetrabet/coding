import copy
def long_sub(a,b):
	
	dp=[ [[0,[-1]] for i in range(len(a))] for j in range(len(b))]
	
	
	for i in range(len(a)):
		if b[0] == a[i]:
			dp[0][i]=[1,[a[i]]]
			for j in range(i,len(a)):
				dp[0][j]=[1,[a[i]]]
			break;
	
	for i in range(len(b)):
		if a[0]==b[i]:
			dp[i][0]=[1,[b[i]]]
			for j in range(i,len(b)):
				dp[j][0]=[1,[b[i]]]
			break;
	
	for i in range(1,len(b)):
		for j in range(1,len(a)):
			if b[i]==a[j]:
				l1= copy.deepcopy(dp[i-1][j-1][1])
				l1.append(a[j])
				#v1=[dp[i-1][j][0]+1,l1]
				#dp[i][j]=copy.deepcopy(max(v1,dp[i][j-1]))
				v1=[dp[i][j-1][0]+1,l1]
				dp[i][j]=copy.deepcopy(max(v1,dp[i-1][j]))

			else:
				dp[i][j]=copy.deepcopy(max(dp[i-1][j],dp[i][j-1]))
	
	for x in dp[len(b)-1][len(a)-1][1]:
		print x,
	print
				
	
m,n=raw_input().split()
a=map(int,raw_input().split())
b=map(int,raw_input().split())
#print a
#print b
long_sub(a,b)
			
