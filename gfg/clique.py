# Enter your code here. Read input from STDIN. Print output to STDOUT
t=input()
while(t>0):
    t-=1
    n,m=map(int,raw_input().split())
    if m>=(n*(n-1))/2:
        print n
    else:
        k=1
        cl=2
        m-=n
        n-=1
        while m>0 and k<n/2:
            cl+=1
            m-=n
            k+=1
        if m>0:
            cl+=1
        print cl
