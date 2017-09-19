from copy import deepcopy
from heapq import heappush
from heapq import heappop

class Tic():

	def __init__(self,myturn,n):
		self.turn=myturn
		self.grid=[['_' for i in range(n) ]for i in range(n)]
	def player1_h(self,symbol):
		pass
		return 0
	def successors(state,symbol):
		display=None
		nextStates=[]
		if symbol==0:
			display='X'
		else:
			symbol='O'
		for i in range(3):
			for j in range(3):
				if state.get(i,j)=='_':
					sc=deepcopy(state)
					sc.set(i,j,symbol)
					nextStates.append(sc)

		return nextStates
	
	def get(self,i,j):
		return self.grid[i][j]
	def set(self,i,j,v):
		self.grid[i][j]=v;

def explore(state,nodetype,curlevel,depth,userPlayer): #0 is min node 1 is maxnode
	pass
	if curlevel==depth:
		return state. player1_h(userPlayer)
	neighbors=successors(state)
	scores=[explore(neigh,nodetype^1,curlevel+1,depth,userPlayer) for neigh in neighbors]
	if nodetype==0:
		return min(scores)
	return max(scores)
	
game=Tic('X',3)
for i in range(3):
	for j in range(3):
		print game.get(i,j),
	print
	
