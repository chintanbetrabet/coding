def isOverlap(a,b):
	#print a,b," test"
	if b[1] < a[2]:
	#	print "true"
		return True
	#print b[0],"<",a[1]
	return False
n=input()

while n > 0:
	n-=1
	inter=input()
	inp=(map(int,raw_input().split()))
	ints=[]
	for i in range(inter):
		ints.append([inp[2*i+1]-inp[2*i],inp[2*i],inp[2*i+1]])
	
	last=0
	ints.sort()
	init =[ints[0]]
	print ints
	for i in range(1,len(ints)):
	#	print "last:",init[last],"curr",ints[i]
		if isOverlap(init[last],ints[i]):
			continue
	#		print "overlap"
			#init[last]=[init[last][0],max(ints[i][1],init[last][1])]
		else:
	#		print "No overlap"
			last+=1
			init.append(ints[i])
		print init
	for x in init:
		print x[1],x[2],
	print		
	
			
		
	
	
