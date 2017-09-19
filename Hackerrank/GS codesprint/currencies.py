n=input()
value,s,f,mt=map(int,raw_input().split())
inp=[]
for x in range(n):
	inp.append(map(int,raw_input().split()))

DP=[[[0 for i in range(n+1)] for j in range(n+1)] for k in range(10001)]
#print DP
for i in range(n):
	for j in range(n):
		#print i,j,inp[i][j]
		DP[i][j][0]=inp[i][j]
#distance in one step set
rep=bin(mt)[3:][::-1]
if mt>1:
	cur=0
	for m in rep:
		m=int(m)
		#print "m",m
		if m%2==0:
			#m/=2
			for start in range(n):
				for end in range(n):
					maxd=0
					for mid in range(n):
						#if start!=mid and mid!=end:
							maxd=max(maxd,DP[start][mid][cur]*DP[mid][end][cur])
					#print maxd
					DP[start][end][cur^1]=maxd
			
		else:
			#m/=2
			for end in range(n):
				for start in range(n):
					maxd=0
					for mid1 in range(n):
						for mid2 in range(n):
							#if start!=mid1 and mid1!=mid2 and mid2!=end:
								maxd=max(maxd,DP[start][mid1][cur]*DP[mid1][mid2][cur]*inp[mid2][end])
					DP[start][end][cur^1]=maxd
		cur^=1
	print int((DP[s][f][cur]*value)%(1000000000+7))
else:
	print int((DP[s][f][0]*value)%(1000000000+7))
#print DP
		
							
