#t=input()
n,t=map(int,raw_input().split())
op=set()
while(t>0):
	t-=1
	#n,c=map(int,raw_input().split())
	com=raw_input().split()
	#print com
	if com[0]=="CLICK":
		#print "JI"
		k=com[1]
		if k not in op:
			op.add(k)
		else:
			op.remove(k)
	else:
		op.clear()
	print len(op)
	
		
		
