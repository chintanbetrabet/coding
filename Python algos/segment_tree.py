def gcd(a,b):
	#print "A,B",a,b
	if a<b:
		return gcd(b,a)
	if a%b==0:
		return b
	else:
		return gcd(b,a%b)

#t=input()
G=input()
N=input()
l=map(int,raw_input().strip().split())

seg=[[1,1] for i in range(1,N*2+1)]
for i in range(N):
	seg[N+i]=[l[i],1]
#print seg

for i in range(N-1,-1,-1):
	posr=2*i
	posl=2*i+1
	#print posr,posl
	v=gcd(seg[posr][0],seg[posl][0])
	cn=seg[posr][1]+seg[posl][1]
	seg[i]=[v,cn]
cn=N+1
for i in range(len(seg)):
	if seg[i][0]==G and seg[i][1]!=1 :
		cn=min(cn,seg[i][1])
if cn==N+1:
	print -1
else :
	print cn
	

