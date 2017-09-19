def max_val(v,table):
		#exem=[1,3,4,2,0]
		if v == 0 :
			table[v]=0
			
		if v not in table:
			val= max(v,(max_val(v/2,table)+max_val(v/3,table)+max_val(v/4,table)))
			table[v]=val
		#print "returning %d for %d"%(table[v],v)
		return table[v]

while True:
	try:
		v=input()
		table={}
		max_val(v,table)
		print table[v]
	except EOFError:
		break
	


