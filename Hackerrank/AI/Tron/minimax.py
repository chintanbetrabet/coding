
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

	
