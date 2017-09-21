n,x=map(int,raw_input().split())
l=map(int,raw_input().split())

less,more=[0,0]
for val in l:
	if val>=x:
		more+=1
	else:
		less+=1
print more+(x-less)

	
