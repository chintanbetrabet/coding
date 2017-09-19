#!/bin/python

import sys

def feeOrUpfront(n, k, x, d, p):
	actCost=0
	for x in p:
		actCost+=max((float(x)*p),float(k))
	return max(actCost,len(p)*d)
    # Complete this function

if __name__ == "__main__":
    q = int(raw_input().strip())
    for a0 in xrange(q):
        n, k, x, d = raw_input().strip().split(' ')
        n, k, x, d = [int(n), int(k), int(x), int(d)]
        p = map(int, raw_input().strip().split(' '))
        result = feeOrUpfront(n, k, x, d, p)
        print result

