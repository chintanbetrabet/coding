t=input()
while t>0:
	t-=1
	x11,y11,x12,y12=map(int,raw_input().split())
	x21,y21,x22,y22=map(int,raw_input().split())
	pts=set([tuple([x11,y11]),tuple([x12,y12]),tuple([x21,y21]),tuple([x22,y22])])
	fl=True
	xs=set([x11,x12,x21,x22])
	ys=set([y11,y12,y21,y22])
	if len(pts)<=3:
		fl=True
	elif len(xs)==1 or len(ys)==1:
		if len(xs)==1:
			ly=[[y11,1],[y12,1],[y21,2],[y22,2]]
			ly.sort()
			if ly[0][1]==ly[1][1]:
				fl=False
		if len(ys)==1:
			lx=[[x11,1],[x12,1],[x21,2],[x22,2]]
			lx.sort()
			if lx[0][1]==lx[1][1]:
				fl=False
	else:
		fl=False
		dup=0
	if fl==False:
		print "no"
	else:
		print "yes"
