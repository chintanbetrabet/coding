def isPrime(n):
    for i in range(2,int(pow(n,0.5))+1):
        if n%i==0:
            return 2
    return 1
l=[0,0]
for i in range(2,100001):
    l.append(isPrime(i))
print l
