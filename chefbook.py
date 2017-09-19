n,m=map(int,raw_input().split(' '))
spec=map(int,raw_input().split(' '))
spec=set(spec)
data=[]
for i in range(m):
	l=raw_input().split(' ')
	sbit=int(l[0])
	p=int(l[1])
	text=l[2]
	if sbit in spec:
		data.append([0,-1*p,text])
	else:
		data.append([1,-1*p,text])
data.sort()
for x in data:
	print x[2]
		
