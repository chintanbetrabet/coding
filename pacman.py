#!/usr/bin/python
path=[]
global optlen
optlen=1000000000;
global optpath
optpath=[]

import copy
def dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid,neighbours,visit,road):
	
    if food_r==pacman_r and food_c==pacman_c:
		print len(road)+1
		for x in road:
			print x[0],x[1]
		print pacman_r,pacman_c
			
    road1=copy.deepcopy(road)
    road1.append([pacman_r,pacman_c])
    visit[pacman_r][pacman_c]=len(road)
    for x in neighbours[pacman_r][pacman_c]:
		#print x[0],x[1]
		if x[0] <r and x[0] >=0 and x[1] >=0 and x[1] <c and visit[x[0]][x[1]]>=len(road) and grid[x[0]][x[1]]!='%':
			
			v=0
			dfs(r, c, x[0], x[1], food_r, food_c, grid,neighbours,visit,road1)
							
            
    return 0
pacman_r, pacman_c = [ int(i) for i in raw_input().strip().split() ]
food_r, food_c = [ int(i) for i in raw_input().strip().split() ]
r,c = [ int(i) for i in raw_input().strip().split() ]

neighbours=[]
for i in range(r):
    neighbours.append([[(i-1,j),(i,j-1),(i,j+1),(i+1,j)][::-1] for j in range(c)])
grid = []
for i in xrange(0, r):
    grid.append(raw_input().strip())

visit=[]
for i in range(r):
    visit.append([100000000 for j in range(c)])
#print neighbours
road=[]
dfs(r, c, pacman_r, pacman_c, food_r, food_c, grid,neighbours,visit,road)



