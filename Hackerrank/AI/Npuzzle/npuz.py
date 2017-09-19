from heapq import heappush
from heapq import heappop
from copy import deepcopy

def printstate(A):
    
        for i in range(3):
            for j in range(3):
                    if A[3*i+j]!=9:
                            print A[3*i+j],
                    else:
                            print ' ',
            print
        print
def inversions(A):
    inv=0
    
    for i in range(len(A)):
        for j in range(i,len(A)):
			if(A[i] > A[j]):
				inv+=1
    '''
    for i in range(len(A)*len(A)):
            if A[i]!=i+1:
                    inv+=1
    '''
    return inv
def show(A,n):
	for i in range(n):
		for j in range(n):
			print A[i*n+j],
		print
conf=[]
n=input()
for i in range(n*n):
        conf.append(input())
#print conf
h=[]
qp=0
moves=[]
heappush(h, (inversions(conf), [moves,conf]))
#print h
direc=["UP","LEFT","DOWN","RIGHT"]
ch=inversions(conf)
visited=set()
cnt=0
while True:
	cnt+=1
	status= h[0]
	#print status
	

	Cstate=status[1][1]
	Cmoves=status[1][0]
	visited.add(tuple(Cstate))
	#print Cmoves
	#print inversions(Cstate)
	#show(Cstate,n)
	if inversions(Cstate)==0:
		print len(Cmoves)
		for x in Cmoves:
			print direc[x]
		#show(Cstate,n)
		break
		
	heappop(h)
	zpos=-1
	for i in range(n*n):
		if Cstate[i]==0:
			zpos=i
	cr=zpos/n
	cc=zpos%n
	#print "zero is at ",cr,cc
	if cr > 0:
		copMove=deepcopy(Cmoves)
		copMove.append(0)
		copState=deepcopy(Cstate)
		copState[zpos],copState[(cr-1)*n+cc]=copState[(cr-1)*n+cc],copState[zpos]
		if tuple(copState) not in visited:
					heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))
		
		
	if cc > 0:
		copMove=deepcopy(Cmoves)
		copMove.append(1)
		copState=deepcopy(Cstate)
		copState[zpos],copState[(cr)*n+cc-1]=copState[(cr)*n+cc-1],copState[zpos]
		if tuple(copState) not in visited:
					heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))

		#heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))
		#print "ADDING LEFT:"
		#show(copState,n)
	if cr +1< n:
		copMove=deepcopy(Cmoves)
		copMove.append(2)
		copState=deepcopy(Cstate)
		copState[zpos],copState[(cr+1)*n+cc]=copState[(cr+1)*n+cc],copState[zpos]
		if tuple(copState) not in visited:
					heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))

		#heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))
	if cc+1 <n:
		copMove=deepcopy(Cmoves)
		copMove.append(3)
		copState=deepcopy(Cstate)
		copState[zpos],copState[(cr)*n+cc+1]=copState[(cr)*n+cc+1],copState[zpos]
		if tuple(copState) not in visited:
					heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))

		#heappush(h,(inversions(copState)+len(copMove),[copMove,copState]))
	#break
#print h
'''
for s in h:
	print s[0]
	print s[1][0]
	
	print s[1]
	show(s[1][1],n)
 '''
