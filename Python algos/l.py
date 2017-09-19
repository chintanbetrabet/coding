import re
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
countoverlappingdistinct('100*1','100001abc1101')
