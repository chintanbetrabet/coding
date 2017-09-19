n=input()
while n>0:
	n-=1
	num=input()
	fs=0
	inc=1
	power=1
	while inc > 0:
		inc = num/pow(5,power)
		fs+=inc
		power+=1
	print fs
