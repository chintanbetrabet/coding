n=input()
l=map(int,raw_input().split())
s=[0 for i in range(5) ]
for x in l:
	s[x]+=1
l.sort()
bm1=min(s[1],s[3])
s[1]-=bm1
s[3]-=bm1
#print bm1
bm2=s[2]/2
#print bm2
#print s
s[2]-=2*bm2
bm3=s[3]
if s[1] > 4:
	bm3+=s1[1]/4
	s[1]=s1%4
if s[2] ==1 :
	if s[1] <=2:
		bm3+=1
	else:
		bm3+=2
if s[2]==0:
	bm3+=1
print bm1+bm2+bm3+(1+s[4]/4)
	

	
