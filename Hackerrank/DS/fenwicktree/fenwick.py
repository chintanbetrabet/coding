global gmax
gmax=0
def update(l,h,cl,ch,val,g,index):
	if(l>h):
		return 0
	if(l<cl or h> ch):
		return 0;
	if(l==cl and h==ch):
		g[index]+=val;
		return 1;
	left=2*index+1;
	right=2*index+2;
	lu=update(max(cl,l),min(h,cl+(ch-cl)/2),cl,cl+(ch-cl)/2,val,g,2*index+1);
	ru=update(max(l,cl+(ch-cl)/2+1),h,cl+(ch-cl)/2+1,ch,val,g,2*index+2);
	return lu or ru;

def getValue(index,g,n1):
	sum1=g[n1+index-1];
	ci=n1+index-1;
	while(ci!=0):
		ci=(ci>>1)-((ci&1)^1);
		sum1+=g[ci];
	return sum1;
def traverse(fenwick,i):
    global gmax
    if i>=len(fenwick):
        return 0
    left=traverse(fenwick,2*i+1)
    right=traverse(fenwick,2*i+2)
    if fenwick[i]+max(left,right) > gmax:
        gmax=fenwick[i]+max(left,right)
    return max(left,right)+fenwick[i]
n1,m=map(int,raw_input().split());
siz=1;
n1+=1;
n=n1;
while(n>1):
	n/=2;
	siz*=2;	
	
if(n1&(n1-1)):
	siz*=2;
	siz*=2;
fenwick=[0 for f in range(siz)]
while(m>0):
	m-=1
	l,h,v=map(int,raw_input().split());
	update(l,h,0,siz/2-1,v,fenwick,0);
traverse(fenwick,0)
print gmax
