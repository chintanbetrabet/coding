n=input()
for c in range(1,n+1):
	s=input()
	mp={}
	for s1 in range(s):
		mp[raw_input().strip()]=0
	q=input()
	for s1 in range(q):
		mp[raw_input().strip()]+=1
	minl=min([mp[x] for x in mp])
	print "Case #%d: %d"%(c,minl)
