import re
import time
import numpy

def getS(l):
  s=""
  for i in range(l):
    s+=str(numpy.random.randint(2))
  return s
def countoverlappingdistinct(pattern, thestring):
  total = 0
  start = 0
  there = re.compile(pattern)
  mo = there.search(thestring, start)
  while True and mo is not None:
    total += 1
    start = 1 + mo.start()
    mo = there.search(thestring, start)
  print total
#countoverlappingdistinct('000','10000')

def mycount(pattern,string):
  found=re.search(pattern,string)
  if found is None:
    return 0
  
  cur=0
  st=pattern[0]
  for i in string:
    if i==st:
      break
    else:
      cur+=1
  if cur < len(string):
    return 1+ mycount(pattern,string[cur+1:])
s="aabaaabbaaaa"
s=getS(10000)
#print s
t1=time.clock()
#countoverlappingdistinct('000',s)
print mycount('000',s)
print time.clock()-t1
