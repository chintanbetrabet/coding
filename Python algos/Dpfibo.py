fib=[-1 for i in range(10000)]
fib[0]=0
fib[1]=1
calls=[0 for i in range(10000)]
def ways_get_change(n,denoms,best_change):
   
    if best_change[n]!=-1:
        return best_change[n]
    else:
        tp=[]
        for k in denoms:
            if n<=k:
                print "breaak at k",k
                if n==k:
                    tp.append( max(1,best_change[n]))
                
                break;
            else:
                if n-k>k:
                    #raw_input(" Trying on n-k"+str(n-k)+"k="+str(k))
                    tp.append(ways_get_change(k,denoms,best_change)+ways_get_change(n-k,denoms,best_change))
                    print "appended : ",str(ways_get_change(k,denoms,best_change)+ways_get_change(n-k,denoms,best_change))," for n=",n
            #calls+=1
        best_change[n]=sum(tp)
        print "tp",tp
        return best_change[n]

denoms=[2 ,5, 3, 6]
denoms.sort()

best_change=[-1 for i in range(15) ]
best_change[0]=1
print ways_get_change(10,denoms,best_change)
print best_change
'''
def get_fib(n):
    if fib[n] !=-1:
        return fib[n]
    else:
        fib[n]=get_fib(n-1)+get_fib(n-2)
        return fib[n]
def get_change(n,denoms,best_change):
    if n < 0:
        return 1000000000
    if best_change[n]!=-1:
        return best_change[n]
    else:
        best_change[n]=min([get_change(k,denoms,best_change)+get_change(n-k,denoms,best_change)for k in denoms])
        return best_change[n]
'''
