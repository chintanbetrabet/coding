def getmaxfac(n):
	for i in range(9,0,-1):
	
		if(n%i==0):
			return i;
	

t=input();
while(t>0):
	t-=1
	n=input();
	d=0
	nums=[];
	if(n<10):
		
		print 10+n
		continue
		
	else:
		nextnumt=getmaxfac(n);
		if(nextnumt==1):
			print -1
			continue
		f=0
		while(n>1):
			nextnum=getmaxfac(n);
			nums.append(nextnum);
			if nextnum==1 and n>1:
				#print -1
				f=1
				break;
			n/=nextnum;
			d+=1;
		if f==1:
			print -1
			continue
			
	s=""
	for i in range(d-1,-1,-1):
		s+=str(nums[i])
		
		
	print s
	
