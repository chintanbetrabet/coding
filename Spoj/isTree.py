def dfs(vist,node,vector):
	#print node
	visit[node]=1
	for n in vector[node]:
		if visit[n] ==0:
			dfs(visit,n,vector)

m,n=map(int,raw_input().split())
vector=[[] for i in range(m+1)]
visit=[0 for i in range(m+1)]
for i in range(n):
	e1,e2=map(int,raw_input().split())
	vector[e2].append(e1)
	vector[e1].append(e2)
dfs(visit,1,vector)
if sum(visit) !=m or m!=n+1:
	print "NO"
else:
	print "YES"
		
