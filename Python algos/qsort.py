global s
s=0
def part(l,e):
    lp=0
    rp=len(l)-1
    while lp<rp:
        while l[lp] < e and lp<rp:
            lp+=1
            #cm+=2
        while l[rp] >=e and lp < rp:
            rp-=1
            #cm+=2
        temp=l[lp]
        l[lp]=l[rp]
        l[rp]=temp
        #sw+=1
    print "parts : ",l[0:lp],e,l[lp:]
    return l,lp
def quick(l):
   # print l
    #print "call on ",l
    #raw_input()
    if len(l) <=1:
        return l
    p=l[len(l)-1]
    #print l,p
    global s
    s=s+p
    ll,ind=part(l,p)
    l=quick(ll[0:ind])+ll[ind:ind+1]+quick(ll[ind+1:])
    return l
def part2(l,e,st,fin):
    lp=st
    rp=fin
    if fin-st<=1:
        return l,fin
    print "st",st,"fin",fin
    while lp<rp:
        while l[lp] < e and lp<rp:
            lp+=1
            #cm+=2
        while l[rp] > e and lp < rp:
            rp-=1
            #cm+=2
        temp=l[lp]
        l[lp]=l[rp]
        l[rp]=temp
        #sw+=1
    print "parts : ",l[st:lp],e,l[lp:fin+1]
    return l,lp
def quick2(l,s,e):
   # print l
    #print "call on ",l
    #raw_input()
    if len(l) <=1:
        return 
    p=l[(s+e)/2]
    #print l,p
    ll,ind=part2(l,p,s,e)
    print ll,ind
    raw_input()
    if ind!=s:
        quick2(l,s,ind)
    if ind!=e:
        quick2(l,ind,e)
    #return l
def merge(l,r):
    
    lp=0
    rp=0
    lr=[]
    while lp<len(l) and rp < len(r):
        if l[lp] < r[rp]:
            lr.append(l[lp])
            lp+=1
        else:
            lr.append(r[rp])
            rp+=1
    while lp < len(l):
        lr.append(l[lp])
        lp+=1
    while rp < len(r):
        lr.append(r[rp])
        rp+=1
    return lr
        

def ms(l):
    if len(l)==1:
      return l  
    return merge(ms(l[0:len(l)/2]),ms(l[len(l)/2:]))
lis=[1,2,3,4,5,5,6,7,7]
#lis.sort()
#print ms(lis)
lis=quick(lis)
print lis
print s
'''
lis.sort()
print quick(lis[0:-1])
#print cm,sw
'''
