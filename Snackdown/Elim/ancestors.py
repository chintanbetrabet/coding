def getpar(n):
	par=[-1 for i in range(n+1)]
	visited=[0 for i in range(n+1)]
	g=[[] for i in range(n+1)]
	edges=[]
	for x in range(n-1):
		e1,e2=map(int,raw_input().split())
		g[e1].append(e2)
		g[e2].append(e1)
		edges.append([e1,e2])
	#print edges
	stackptr=0
	stack=[[1,0]]
	heights=[n+1 for i in range(n+1)]
	#print g
	while stackptr<len(stack):
		#print stack[stackptr]
		node=stack[stackptr][0]
		if visited[node]==0:
			#print node
			visited[node]=1
			heights[node]=stack[stackptr][1]
			for x in g[node]:
				if visited[x]==0:
					stack.append([x,stack[stackptr][1]+1])
		stackptr+=1
	#print heights
	
	for x in edges:
		if heights[x[0]] < heights[x[1]]:
			par[x[1]]=x[0]
		else:
			par[x[0]]=x[1]
	#print par
	return par

t=input()
while t>0:
	t-=1
	n=input()
	par1=getpar(n)
	par2=getpar(n)
	
	for i in range(1,n+1):
		anc1=[]
		anc2=[]
		cp=par1[i]
		while cp!=-1:
			
			anc1.append(cp)
			cp=par1[cp]
		cp=par2[i]
		while cp!=-1:
			anc2.append(cp)
			cp=par2[cp]
		cnt=0
		com=[]
		for x in anc1:
			if x in anc2:
				cnt+=1
		
		print cnt,
		
	print
		
