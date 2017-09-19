n=input()
if sum([x%2 for x in map(int,raw_input().split())])==0 :
	print "Second" 
else:
	print "First"
