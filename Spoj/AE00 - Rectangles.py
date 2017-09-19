n=input()
rec=0
for i in range(1,int(pow(n,0.5))+1):
	rec+=n/i;
	print "after side=",i," rec=",rec
print rec	
