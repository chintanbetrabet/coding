m,n=map(int,raw_input().split())
minis=[]
for k in range(n):
	minis.append(min(map(int,raw_input().split())))
print max(minis)
	
