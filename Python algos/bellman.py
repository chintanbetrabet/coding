# Enter your code here. Read input from STDIN. Print output to STDOUT
# Enter your code here. Read input from STDIN. Print output to STDOUT
#!/bin/python
def bellman(graph,n):
	bellout=[[1000000000  for i in range(n)] for j in range(n)]
	for k in range(n):
		bellout[k][k]=0
	for i in range(n):
		for x in range(n):
			bellout[i][x]=min(graph[i][x],bellout[i][x])
	for k in range(n):
		for j in range(n):
			v=bellout[k][j]
			for i in range(n):
				v=min(v,(bellout[k][i]+bellout[i][j]))
			bellout[k][j]=v
	
	#print bellout
	return bellout

	


import sys


t =1
for a0 in xrange(t):
    
    n,m = raw_input().strip().split(' ')
    n,m = [int(n),int(m)]
    graph=[[1000000000 for i in range(n+1)] for j in range(n+1)]
    for a1 in xrange(m):
        x,y,r = map(int,raw_input().strip().split(' '))
        graph[x][y]=(r)
        #graph[y][x]=(r)
    res=bellman(graph,n+1)
    s = int(raw_input().strip())
    for x in range(s):
        p,q=map(int,raw_input().strip().split(' '))
        if res[p][q] >1000000000:
            print -1
        else:
            print res[p][q]
            

