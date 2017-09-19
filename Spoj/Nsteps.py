eq={}
neq={}
eq[0]=0
neq[0]=2
v=0
for i in range(1,10001):
	if v%2==0:
		v+=1
	else:
		v+=3
	eq[i]=v
v=2
for i in range(1,10001):
	if v%2==0:
		v+=1
	else:
		v+=3
	neq[i]=v
t=input()
while t>0:
	t-=1
	x,y=map(int,raw_input().split())
	if x==y:
		print eq[y]
	elif x==y+2:
		print neq[y]
	else:
		print 	"No Number"
		
