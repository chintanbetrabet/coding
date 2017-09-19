# Enter your code here. Read input from STDIN. Print output to STDOUT
t=input()

while t>0:
    t-=1
    n=input()
    A=map(int,raw_input().split())
    B=map(int,raw_input().split())
    visit=[0 for k in range(n)]
    A1=[[A[i],i] for i in range(n)]
    B1=[[B[i],i] for i in range(n)]
    k=0
    As=0
    Bs=0
    while k<n:
        if k%2==0:
            x=max(B1)
            ind=x[1]
            sc=x[0]
            visit[ind]=1
            B1=[]
            for i in range(n):
                if visit[i]==0:
                    B1.append([B[i],i])
            As+=A[ind]
        else:
            x=max(A1)
            ind=x[1]
            sc=x[0]
            visit[ind]=1
            A1=[]
            for i in range(n):
                if visit[i]==0:
                    A1.append([A[i],i])
            Bs+=B[ind]
        k+=1
    print As,Bs
    if As > Bs :
        print "First"
    elif Bs > As:
        print "Second"
    else:
        print "Tie"
   
            
            
        
    
    
