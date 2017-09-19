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
    raise ValueError

def q(l1,l2,a,b):
	s=0
	for i in range(a):
		for j in range(b):
			s+=l1[i]*l2[j]
	return s
def smartQ(psX,psY,sx,sy,sv,tx,ty):
	f1=sv
	f2=(psX[tx-1]-psX[sx-1])*psY[sy-1]
	sx=tx
	f1=f1+f2
	f2=(psY[ty-1]-psY[sy-1])*psX[sx-1]
	return f1+f2
	
def sumXZ(X,Y,qlist):
	
	sumq=0
	psX=[0]
	psY=[0]
	psZ=[0]
	for x in X:
		psX.append(psX[-1]+x)
	for x in Y:
		psY.append(psY[-1]+x)
	
	psX=psX[1:]
	psY=psY[1:]
	sx=qlist[0][0]
	sy=qlist[0][1]
	sv=q(X,Y,sx,sy)
	#print sv,sv
	sumq+=sv
	for i in range(1,len(qlist)):
			tx=qlist[i][0]
			ty=qlist[i][1]
			#bv=q(X,Y,tx,ty)
			dpV=smartQ(psX,psY,sx,sy,sv,tx,ty)
			sx=tx
			sy=ty
			sv=dpV
			#print bv,dpV
			sumq+=dpV
	return sumq
			
		

'''
	a1=3
	a2=2
	t1=7
	t2=4
	print q(X,Y,a1,a2)
	print q(X,Y,t1,t2)
	f1=q(X,Y,a1,a2)
	f2=(psX[t1-1]-psX[a1-1])*psY[a2-1]
	a1=t1
	f1=f1+f2
	f2=(psY[t2-1]-psY[a2-1])*psX[a1-1]
	print f1+f2
X=[45,6,8,46,84,64,68,46,4]
Y=[7,8,9,6,5,23,54,31,8,46,4,8]
ql=[[2,3],[3,5],[3,6],[5,8]]
ql.sort()
test(X,Y,ql)
'''
X=[1,2,3,4,5,6]
Y=[0,1,2,4,5,6]

e1= find_le(X,3)
e2=find_le(Y,3)
ql=[[e1,e2]]
print ql
print sumXZ(X,Y,ql)

