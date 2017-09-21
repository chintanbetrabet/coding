# Enter your code here. Read input from STDIN. Print output to STDOUT
n,k,q=map(int,raw_input().split(' '))
lis=map(int,raw_input().split(' '))
while len(lis)<n:
    lis1=[]
    if len(lis)<n:
        lis1=map(int,raw_input().split(' '))
    if len(lis1)>0:
        for x in lis1:
            lis.append(x)
    
for i in range(n):
    qi=int(raw_input())
    
    print lis[(qi+n-k)%(n)]
