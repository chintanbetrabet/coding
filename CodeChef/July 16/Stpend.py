t=input()
for i in range(t):
    n=input()
    marks=map(int,raw_input().split(' '))
    ma=max(marks)
    mi=min(marks)
    av=sum(marks)/float(n)
    if av >= 4.0 and mi > 2 and ma ==5 :
        print "Yes"
    else:
        print "No"
    
