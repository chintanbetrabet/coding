import copy
perms=[]
def permute(l):
    if len(l)==1:
        yield l
    else:
        for i in range(len(l)):
            l2=[]
            for j in l:
                if j!=l[i]:
                    l2.append(j)
            for p in permute(l2):
                yield l[i:i+1]+p
    
global c
c=0
def dfs(g,n,v,d):
    #print n,d
    v[n]=1
    for ed in g[n]:
        #print ed
        if v[ed[0]]==0:
            v[ed[0]]=1
            global c
            c+=d+ed[1]
            dfs(g,ed[0],v,d+ed[1])
edges=input()

for x in permute(range(1,edges+1)):
    perms.append(x)

g=[[] for i in range(10)]
while edges>1:
    edges-=1
    p,q,w=map(int,raw_input().split())
    g[p].append([q,w])
    g[q].append([p,w])
for p in perms:
    #print p
    v=[0 for i in range(1,10)]
    for node in p:
        #print node
        v1=copy.deepcopy(v)
        dfs(g,node,v1,0)
        #print c
        v[node]=1
        #print v
print  c
