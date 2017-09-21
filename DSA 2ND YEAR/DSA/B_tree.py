import copy
import random
import numpy
import time
import sys
sys.setrecursionlimit(6000)
inorder=[]
mh=0
run=0
def getAll(n):
    b=set()
    a=[x for x in range(1,n+1)]
    #print a
    while a:
       tu=tuple(a)
       b.add(tu)
       a= nextPermutationKnuth(a)


    #print count
    return b

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

class node():
    mh=0
    def __init__(self,data=0):
        self.data=data
        self.left=0
        self.right=0
        #self.mh=0

    def is_leaf(self):
        if self.right==0:
            return true
        return false
    def add(self,data):

        if data > self.data and self.right==0:
            self.right=node(data)
        else :
            if data > self.data:
                self.right.add(data)
        if data <= self.data and (self.left==0):
            self.left=node(data)
        else :
            if data<=self.data:
                self.left.add(data)
    def show(self,cur,h):
        #print mh
        if node.mh < h:
           node.mh=h
        #print cur.data

        if cur.left.__class__==node().__class__:
            cur.show(cur.left,h+1)

        if cur.right.__class__==node().__class__:
            cur.show(cur.right,h+1)
        inorder.append(cur.data)
'''def show(self,cur):
      if cur.left.__class__==node().__class__:
            cur.show(cur.left)

      if cur.right.__class__==node().__class__:
         cur.show(cur.right)
      inorder.append(cur.data)
'''
def cnt_preO(n):
   for i in range(1,n):
       t1=time.clock()
       perms=getAll(i)
       #print len(perms)
       #print
       s=set()

       for x in perms:
           #print x
           del inorder[0:]
           Tree=node(8000)
           for y in x:
               Tree.add(y)
           Tree.show(Tree,0)
           tu=tuple(inorder)
           s.add(tu)
           #print tu
       print str(i)+" "+str(len(s))+" in "+str(time.clock()-t1)
def getHeightRU(r1,r2,r3,m):
   for y in range(0,r1):
      Tree=node(m)
      lis=[]

      for x in range(1,r2):
         r=random.randint(1,r3)
         Tree.add(r)
         lis.append(r)
      h=0
      mh=0
      node.mh=0
      Tree.show(Tree,h)
      #print lis
      print node.mh
      #print
def getHeightRN(r1,r2,lim,m,s):
   t1=time.clock()
   for y in range(0,r1):
      global run
      run=run+1
      Tree=node(lim)
      lis=[]

      for x in range(1,r2):
         r=int(numpy.random.randn()*s+m)
         Tree.add(r)
         lis.append(r)
      h=0
      mh=0
      node.mh=0
      Tree.show(Tree,h)
      #print lis
      print str(node.mh) + " "+str(run)+" "+str(time.clock()-t1)
      #print
#getHeightRN(1000,5000,800000000,100,100000000)
def getHeightonInsertUniform():
    Tree =node(80000000000000)
    for i in range(5000):
        x=random.randrange(1,100000)
        Tree.add(x)
        Tree.show(Tree,0)
        print str(i)+"  "+str(node.mh)
        node.mh=0
def getHeightonInsertNormal(m,s):
    Tree =node(80000000000000)
    for i in range(5000):
        x=r=int(numpy.random.randn()*s+m)
        Tree.add(x)
        Tree.show(Tree,0)
        print str(i)+"  "+str(node.mh)
        node.mh=0



 

