import copy
count=0
def permute(b,a,l,r):
   global count
   count=count+1
   if l == r:
       c=copy.deepcopy(a)
       c=tuple(c)
       b.add(c)
   else:
       for i in range(0,r+1):
          a[l],a[i]=a[i],a[l]
          permute(b,a, l+1, r);
          a[l],a[i]=a[i],a[l]
def heapify(a,i):
   
    if i>0:
        if a[i]<a[(i-1)/2]:
            
            a[i],a[(i-1)/2]=a[(i-1)/2],a[i]
            heapify(a,(i-1)/2)
def getAll(n):
    b=set()
    a=[x for x in range(1,n+1)]
    while a:
       tu=tuple(a)
       b.add(tu)
       a= nextPermutationKnuth(a)
      
      
      
    #print count
    return b
    
def count_heaps(n):           

    perms=getAll(n)
    Total=set()
    for x in perms:
        heap=[]
        hs=0
        for i in range(5):
            heap.append(x[i])
            heapify(heap,hs)
            hs=hs+1
        heap=tuple(heap)
        Total.add(heap)
    return len(Total)
def nextPermutationKnuth(perm):
    
    k0 = None
    for i in range(len(perm)-1):
        if perm[i]<perm[i+1]:
            k0=i
    if k0 == None:
        return None

    l0 = k0+1
    for i in range(k0+1, len(perm)):
        if perm[k0] < perm[i]:
            l0 = i

    perm[k0], perm[l0] = perm[l0], perm[k0]
    perm[k0+1:] = reversed(perm[k0+1:])
    return perm
print count_heaps(10)








