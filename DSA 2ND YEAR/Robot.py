def next_pos(N,move,val,x,y):
    if val>N:
        print "%d %d"%(x,y)
    else:
        if move==1:
            x+=val
            move+=1
        else:
            if move==2:
                y+=val
                move+=1
            else:
                if move==3:
                    x-=val
                    move+=1
                else:
                    if move==4:
                        y-=val
                        move=1;
        next_pos(N,move,val+1,x,y)
next_pos(2,1,1,0,0)    
