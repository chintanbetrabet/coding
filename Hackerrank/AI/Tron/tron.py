#!/bin/python
from copy import deepcopy


def maxNode(player_user,player_rival,player_move,board,depth,maxdepth):
	if depth==maxdepth:
		return board.score(player_user)
	else:
		if len(board.successors(player_move)) ==0:
			#print "NO SUCCESSORS FOR player :",player_move," at pos",board.xpl,board.ypl
			#board.show()
			return 0
		if player_move==player_user:
			return max([minNode(player_user,player_rival,player_rival,succ,depth+1,maxdepth) for succ in board.successors(player_move)])
		if player_move!=player_user:
			return max([minNode(player_user,player_rival,player_user,succ,depth+1,maxdepth) for succ in board.successors(player_move)])
			
	pass
def minNode(player_user,player_rival,player_move,board,depth,maxdepth):
	if depth==maxdepth:
		return board.score(player_user)
	else:
		if len(board.successors(player_move)) ==0:
			return 0
		if player_move==player_user:
			return min([maxNode(player_user,player_rival,player_rival,succ,depth+1,maxdepth) for succ in board.successors(player_move)])
		if player_move!=player_user:
			return min([maxNode(player_user,player_rival,player_user,succ,depth+1,maxdepth) for succ in board.successors(player_move)])

	


class Board():
	def __init__(self,b,xpl,ypl,xopp,yopp,pl,rival):
		self.board=deepcopy(b);
		self.xpl=xpl
		self.ypl=ypl
		self.xopp=xopp
		self.yopp=yopp
		self.pl=pl
		self.rival=rival
		self.prev=""
	def show(self):
		for x in self.board:
			print x
	def successors(self,player):
		#print 'CONFIG'
		#self.show()
		#print
		succ=[]
		block=['-','#']
		if player==self.pl:
			if (self.xpl+2<len(self.board) and ( self.board[self.xpl+2][self.ypl] in block and self.board[self.xpl+1][self.ypl]=='-' ) or (self.xpl+1<len(self.board) and self.board[self.xpl+1][self.ypl]=='-' ) ) and self.prev!="UP":
				
				st=deepcopy(self)
				st.board[self.xpl+1][self.ypl]=player
				st.prev="DOWN"
				st.xpl+=1
				succ.append(st)
			if ((self.ypl+2<len(self.board[0]) and (self.board[self.xpl][self.ypl+2] in block and self.board[self.xpl][self.ypl+1]=='-' )) or (self.ypl+1<len(self.board[0]) and self.board[self.xpl][self.ypl+1]=='-') ) and self.prev!="LEFT":
				st=deepcopy(self)
				st.board[self.xpl][self.ypl+1]=player
				st.prev="RIGHT"
				st.ypl+=1
				succ.append(st)
    			if ((self.xpl-2 > 0 and (self.board[self.xpl-2][self.ypl] in block and self.board[self.xpl-1][self.ypl]=='-')) or (self.xpl-1 > 0 and self.board[self.xpl-1][self.ypl]=='-')) and self.prev!="DOWN":
				st=deepcopy(self)
				st.board[self.xpl-1][self.ypl]=player
				st.prev="UP"
				st.xpl-=1
				succ.append(st)
			
    			if ((self.xpl-2 > 0 and (self.board[self.xpl-2][self.ypl] in block and self.board[self.xpl][self.ypl-1]=='-') ) or (self.ypl-1 > 0 and self.board[self.xpl][self.ypl-1]=='-')) and self.prev!="RIGHT":
				st=deepcopy(self)
				st.board[self.xpl][self.ypl-1]=player
				st.prev="LEFT"
				#print "l1"
				#st.show()
				st.ypl-=1
				succ.append(st)
			'''
			if len(succ)==0:
				print "NO SUCC FOR ",self.xopp,self.yopp,self.rival,self.prev
				self.board[self.xpl][self.ypl]='X'
				self.show()
			'''
		else:
			if ((self.xopp+2<len(self.board) and self.board[self.xopp+2][self.yopp] in block and self.board[self.xopp+1][self.yopp]=='-' ) or (self.xopp+1<len(self.board) and self.board[self.xopp+1][self.yopp]=='-')) and self.prev!="UP":
				st=deepcopy(self)
				st.board[self.xopp+1][self.yopp]=player
				st.prev="DOWN"
				st.xopp+=1
				succ.append(st)
			if ((self.yopp+2<len(self.board[0]) and self.board[self.xopp][self.yopp+2] in block and self.board[self.xopp][self.yopp+1]=='-') or (self.yopp+1<len(self.board[0]) and self.board[self.xopp][self.yopp+1]=='-')) and self.prev!="LEFT":
				st=deepcopy(self)
				st.board[self.xopp][self.yopp+1]=player
				st.prev="RIGHT"
				st.yopp+=1
				succ.append(st)
    			if ( (self.xopp-2 > 0 and self.board[self.xopp-2][self.yopp] in block and self.board[self.xopp-1][self.yopp]=='-') or (self.xopp-1 > 0 and self.board[self.xopp-1][self.yopp]=='-')) and self.prev!="DOWN":
				st=deepcopy(self)
				st.board[self.xopp-1][self.yopp]=player
				st.prev="UP"
				st.xopp-=1
				succ.append(st)
			
    			if ( (self.yopp-2 > 0 and self.board[self.xopp][self.yopp-2] in block and self.board[self.xopp][self.yopp-1]=='-') or (self.yopp-1 > 0 and self.board[self.xopp][self.yopp-1]=='-' )) and self.prev!="RIGHT":
				st=deepcopy(self)
				st.board[self.xopp][self.yopp-1]=player
				st.prev="LEFT"
				st.yopp-=1
				succ.append(st)
			'''
			if len(succ)==0:
				print "NO SUCC FOR ",self.xopp,self.yopp,self.rival,self.prev
				self.board[self.xopp][self.yopp]='X'
				self.show()
			'''
		
		return succ
	def score(self,player):
		return len(self.successors(self.pl))
	
		
	
player = raw_input()
pos = raw_input().split()
[x,y, o_x, o_y] = [int(i) for i in pos]
board = []
rival=""
for i in xrange(0, 15):
	row=[]
	for sq in raw_input():
		if sq!='-' and sq!=player and sq!='#':
			rival=sq
		row.append(sq)
	board.append(row)
if board[x][y]==player:
	objboard=Board(board,x,y, o_x, o_y,player,rival)
else:
	objboard=Board(board,o_x, o_y,x,y,player,rival)
	
#print "rival",rival
sc=""
prev=""
try:
		f=open("previous",'r')
		prev=f.read()
		#print prev
		f.close()
except:
		prev=""
f=open('previous','w')
ms=0
depth=1
oppo={}
oppo["DOWN"]='UP'
oppo["UP"]='DOWN'
oppo["RIGHT"]='LEFT'
oppo["LEFT"]='RIGHT'
oppo[""]=''
ans=""
while ms==0 and depth>0:
	
	for succ in objboard.successors(player):
		#succ1=deepcopy(succ)
		#succ1.show()
		#print succ.prev
		some= minNode(player,rival,player,succ,0,0)
		if some > ms and succ.prev!=oppo[prev] or True:
			ms=some
			#print "got score:",some," on ",succ.prev
			ans=succ.prev
	#move = nextMove(player,x,y,o_x,o_y,board)
	depth-=1

	
f.write(ans)
print ans
