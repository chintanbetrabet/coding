import bisect
from bisect import bisect_left
from bisect import bisect_right
def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return i
    return 0
def quer(l1,l2,a,b):
	s=0
	#print l1,l2
	for i in range(a):
		for j in range(b):
			s+=l1[i]*l2[j]
			#print i,j
	return s
def smartQ(psX,psY,sx,sy,sv,tx,ty):
	f1=sv
	f2=(psX[tx-1]-psX[sx-1])*psY[sy-1]
	sx=tx
	f1=f1+f2
	f2=(psY[ty-1]-psY[sy-1])*psX[sx-1]
	return f1+f2
def brute(X,Y,Z):
	s=0
	for x in X:
		for y in Y:
			for z in Z:
				if max(x,y,z)==y:
					s+=(x+y)*(y+z)
					s%=1000000007
	return s%1000000007
				
def sumXZ(psX,psY,X,Y,qlist):
	if len(qlist)==0:
		return 0
	sumq=0
	sx=qlist[0][0]
	sy=qlist[0][1]
	#print sx,sy,X,Y
	sv=quer(X,Y,sx,sy)
	#print sv,sv
	for i in range(1,len(qlist)):
			tx=qlist[i][0]
			ty=qlist[i][1]
			#bv=q(X,Y,tx,ty)
			dpV=smartQ(psX,psY,sx,sy,sv,tx,ty)
			sx=tx
			sy=ty
			sv=dpV
			#print bv,dpV
			sumq+=dpV%1000000007
			sumq%=1000000007
	return sumq
	

t=input()
for te in range(t):
	p,q,r=map(int,raw_input().split())
	X=map(int,raw_input().split())
	Y=map(int,raw_input().split())
	Z=map(int,raw_input().split())
	X.sort();
	Y.sort();
	Z.sort();
	psX=[0]
	psY=[0]
	psZ=[0]
	for x in X:
		psX.append(psX[-1]+x)
	for x in Y:
		psY.append(psY[-1]+x)
	for x in Z:
		psZ.append(psZ[-1]+x)
	psX=psX[1:]
	psY=psY[1:]
	psZ=psZ[1:]
	s=0
	ql=[]	
	for y in Y:
		e1= find_le(X,y)
		e2=find_le(Z,y)
		ql.append([e1,e2])
		#print "y2 term=",y*y*e1*e2
		s+=y*y*e1*e2
		s%=1000000007
		#print "xy term=",y*psX[e1-1]*e2
		s+=y*psX[e1-1]*e2
		s%=1000000007
		#print "zy term",y*psZ[e2-1]*e1
		s+=y*psZ[e2-1]*e1
		s%=1000000007
		#s+=psX[e1-1]*psZ[e2-1]
		#s%=1000000007
	ql.sort()
	#print ql
	s+=sumXZ(psX,psY,X,Z,ql)
	#print quer(X,Z,3,2)
	s%=1000000007
	print s==brute(X,Y,Z),s,brute(X,Y,Z)	
				
