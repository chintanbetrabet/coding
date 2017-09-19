import numpy as np

class Model():
	
	def __init__(self,feat):
		self.weights=np.random.random([feat+1,1])
		#print self.weights.shape
		#print self.weights
				
	def predict(self,X):
		#add bias term here
		X=np.insert(X,0,1,axis=1)
		y=X.dot(self.weights)  # y=Ot.X
		return y
		
	def gradient(self,X,y):
		Xb=np.insert(X,0,1,axis=1)
		mv=0
		for i in xrange(Xb.shape[0]):
			mv=max(mv,max(y[i]))
		#print mv
		#W1=self.weights/mv
		#y1=y/mv
		W1=self.weights
		y1=y
	
		mylabel=Xb.dot(W1)
		
		
		error=y1-mylabel
		#print "mylabel",mylabel
		#print "Y",y1
		#print "error",error
		#print
		#print "labels size",mylabel.shape
		#return self.weights
		#print error.shape
		Xb=Xb.T
		#print error.shape
		#print Xb.dot(error)
		#print "G",Xb.dot(error)/X.shape[0]
		return Xb.dot(error)/X.shape[0]
	def loss(self,X,y):
		Xb=np.insert(X,0,1,axis=1)
		L=0
		mv=0 
		for i in xrange(Xb.shape[0]):
			mv=max(mv,max(Xb[i]),(y[i]))
		W1=self.weights/mv
		y1=y/mv
		#W1=self.weights
		#y1=y
	
		Y1=Xb.dot(W1)
		Y1-=y
		Y1/=X.shape[0]
		Y1=pow(Y1,2)
		return sum(Y1)/2
	def train(self,X,y,iterations,alpha):
		#print "initial Loss",self.loss(X,y)
		pl=self.loss(X,y)[0]
		while iterations > 0:
			iterations-=1
			self.weights=self.weights+(self.gradient(X,y)*(alpha))
			#print "WEIGHT"
			#print self.weights
			#print "New Loss",self.loss(X,y)
			'''
			if pl < self.loss(X,y)[0]:
				print "ERROR"
				break
			
			if pl - self.loss(X,y)[0] < 0.001:
				#print "Too little change between",pl, self.loss(X,y)[0]
				break
			pl=self.loss(X,y)[0]
			'''
		

feat,train=map(int,raw_input().split())
Xtrain=[]
ytrain=[]
#print train
for i in range(train):
	inp=map(float,raw_input().split())
	Xtrain.append(inp[:-1])
	
	ytrain.append([inp[-1]])

ytrain=np.array(ytrain)
Xtrain=np.array(Xtrain)

#print Xtrain.shape
#print ytrain.shape

model = Model(feat)

model.train(Xtrain,ytrain,5000,0.01)

Xtest=[]
test=input()
for t1 in range(test):
	Xtest.append(map(float,raw_input().split()))
Xtest=np.array(Xtest)
#print Xtest
Y1=model.predict(Xtest)
for x in Y1:
	print x[0]
'''

print "DIFF"
for i in range(Xtrain.shape[0]):
	print Y1[i],ytrain[i]



'''
