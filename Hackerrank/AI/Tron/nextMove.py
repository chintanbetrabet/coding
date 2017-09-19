def nextMove(player,x,y,o_x,o_y,board):
    prev=""
    try:
		f=open("myfile",'r')
		prev=f.read()
		#print prev
		f.close()
    except:
		prev=""
    f=open('myfile','w')
    if x+1<len(board) and board[x+1][y]=='-' and prev!="UP":
		#print x,y
		f.write("DOWN")
		f.close()
		return "DOWN"
    elif y+1<len(board[0]) and board[x][y+1]=='-' and prev!="LEFT":
		f.write("RIGHT")
		f.close()
	        return "RIGHT"
    elif x-1 > 0 and board[x-1][y]=='-' and prev!="DOWN":
		f.write("UP")
		f.close()
        	return "UP"
    else:
		f.write("LEFT")
		f.close()
        	return "LEFT"
