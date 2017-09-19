all_p=[[] for i in range(12)]
all_p[1]=[[1]]
pc=0
for i in range(2,12):
	p1=[]
	for x in all_p[i-1]:
		
		for k in range(len(x)+1):
			p2=x[0:k]+[(i)]+x[k:]
			pc+=1
			p1.append(p2)
	all_p[i]=p1
#print pc
#for a in all_p:
#	print len(a)
	#for k in a:
	#	print k	
q = int(raw_input().strip())
for a0 in xrange(q):
    n, k = raw_input().strip().split(' ')
    n, k = [int(n), int(k)]
    c=0
    for x in all_p[n]:
        hap=0
        if x[0]< x[1]:
            hap+=1
        for i in range(1,n-1):
            if x[i]< x[i+1] or x[i]<x[i-1]:
                hap+=1
        if x[n]<x[n-1]:
            hap+=1
        if hap>=k:
            c+=1
    print c
        
	
