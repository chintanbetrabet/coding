inp=map(int,raw_input().strip().split(" "))
while [0,0,0]!=inp:
	if inp[1]-inp[0] == inp[2]-inp[1]:
		print "AP",(inp[2]+inp[2]-inp[1])
	else:
		print "GP",inp[2]*(inp[2]/inp[1])
	
	inp=map(int,raw_input().split())
