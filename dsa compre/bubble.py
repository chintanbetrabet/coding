import copy
def bubble(l,asc_desc):
    l1=copy.deepcopy(l)
    comps=0
    n=len(l)
    if asc_desc==1:
		for i in range(n):
			for j in range(n-i-1):
				if l1[j]>l1[j+1]:
					l1[j],l1[j+1]=l1[j+1],l1[j]
					comps+=1
    if asc_desc==0:
		for i in range(n):
			for j in range(n-i-1):
				if l1[j]<l1[j+1]:
					l1[j],l1[j+1]=l1[j+1],l1[j]
					comps+=1
    #print l1,comps,asc_desc
    return comps
n=input()
l=map(int,raw_input().split())
m1=[]
maxi=[0]
mv=0
for e in range(1,len(l)):
    if l[mv] < l[e]:
        mv=e
    maxi.append(mv)
for x in range(n):
    if maxi[x]==x:
        m1.append([bubble(l[0:x+1],1)+bubble(l[x:],0),x])
print min(m1)[0]
