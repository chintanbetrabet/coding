t=input()
for te in range(t):
    n=input()
    cn=0
    l=map(int,raw_input().split(' '))
    if n>1:
        if l[0]!=l[1]:
            cn+=1
        for v in range(1,n-1):
                if l[v]!=l[v+1]:
                    cn+=2
    print cn
        
        
