a=map(int,raw_input().split())
target=input()


			a=A;target=B;
			a.sort()
			closest=1000000000000
			for x in range(len(a)):
				lp=0
				rp=len(a)-1
				while lp<rp:
					#print "x=%d lp=%d rp=%d"%(x,lp,rp)
					if lp==x:
						lp+=1
						continue
					elif rp==x:
						rp-=1
						continue
					else:
						if a[lp]+a[rp]+a[x] > target:				
							if abs(a[lp]+a[rp]+a[x]-target)<=abs(closest-target):
								closest=a[lp]+a[rp]+a[x]
								#print "cl at x=%d,lp=%d,rp=%d =%d"%(x,lp,rp,a[lp]+a[rp]+a[x])
							rp-=1
						else:
							if abs(a[lp]+a[rp]+a[x]-target)<=abs(closest-target):
								closest=a[lp]+a[rp]+a[x]
								#print "cl at x=%d,lp=%d,rp=%d =%d"%(x,lp,rp,a[lp]+a[rp]+a[x])
							lp+=1
			return closest
				
	
