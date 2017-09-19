from copy import deepcopy
def repeatedPerms(n,k):
	perms=[]
	qp=0
	ans=[]
	for i in range(1,n+1):
		perms.append([i])
	while qp< len(perms):
		top=perms[qp]
		qp+=1
		if len(top)<k:
			for i in range(1,n+1):
				cop=deepcopy(top)
				cop.append(i)
				#print "cop", cop 
				perms.append(cop)
		elif len(top)==k:
			ans.append(top)
		else:
			break
	return ans
def evaln(perm,p,n,m):
	val=0
	for i in range(n):
		val+=perm[i]*pow(p,n-1-i,m)
		val%=m
	return val%m
n,k,p,m=map(int,raw_input().split())
#ans=repeatedPerms(k,n)
if p+1<=k:
	for i in range(n-2):
		print 1,
	print 1,p+1
	for i in range(n-2):
		print 1,
	print 2,1
	
'''
else:
mp={}
fl=0
x=0
while k*pow(p,x)<m or x<2:
	x+=1
#print x
ans=repeatedPerms(k,x)
#print ans
l=len(ans)
i=0
for perm in ans:
	#print perm,evaln(perm,p,x,m)
	if evaln(perm,p,x,m) in mp:
		for v in range(n-x):
			print 1,
		for v in mp[evaln(perm,p,x,m)]:
			print v,
		print
		for v in range(n-x):
			print 1,
		for v in perm:
			print v,
		break
	else:
		mp[evaln(perm,p,x,m)]=perm
'''
