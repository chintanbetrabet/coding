#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int> 
#define ll long 
int update(int l,int h,int cl,int ch,ll val,vector<ll> &g,int index)
{
//cout<<" call on "<<l<<" "<<h<<" index:"<<index<<endl;
//=loc[index].first,ch=loc[index].second;
if(l>h){
//cout<<"out of bounds"<<endl;
return 0;}

if(l<cl || h> ch){
//cout<<" not in range: "<<cl<<","<<ch<<" for "<<l<<" "<<h<<endl; 
return 0;
}
if(l==cl&&h==ch){
//cout<<" updating  at "<<cl<<"  "<<ch<<endl;
g[index]+=val;
return 1;
}
else{
int left=2*index+1;
int right=2*index+2;
int lu=update(max(cl,l),min(h,cl+(ch-cl)/2),cl,cl+(ch-cl)/2,val,g,2*index+1);
int ru=update(max(l,cl+(ch-cl)/2+1),h,cl+(ch-cl)/2+1,ch,val,g,2*index+2);
return lu||ru;
}
return 0;
}
ll getValue(int index,vector<ll> &g,int n1)
{
int sum=g[n1+index-1];
int ci=n1+index-1;
while(ci!=0)
	{
	ci=(ci>>1)-((ci&1)^1);
	sum+=g[ci];
	}
return sum;
}
void assign(vector<pair<int,int> >& g,int index,int l,int h,int n)
{
g[index]=pi(l,h);
if(2*index+1>n)return;

assign(g,2*index+1,l,l+(h-l)/2,n);
assign(g,2*index+2,l+(h-l)/2+1,h,n);

}

int main()
{

	int n1;
	int siz=1;
	cin>>n1;
	n1++;
	int n=n1;
	while(n>1)
	{
		n/=2;
		siz*=2;	
	}
	if(n1&(n1-1)){
		siz*=2;
	}
	siz*=2;
	//cout<<siz<<endl;
	//vector<pair<int,int> > upvalues(siz);
	//assign(upvalues,0,0,siz/2-1,siz);
	vector<ll> fenwick(siz,0);
	
	int m;
	cin>>m;
	while(m--)
	{
	int l,h;
	ll v;
	cin>>l>>h>>v;
	//cout<<" query:"<<l<<" "<<h<<" "<<v<<endl;
	update(l,h,0,siz/2-1,v,fenwick,0);
	
		for(int i=0;i<siz;i++)
	{
	//cout<<i<<" range: "<<upvalues[i].first<<","<<upvalues[i].second<<"  : "<<fenwick[i]<<endl;
	}
		for(int i=0;i<siz/2;i++)
		{
		//cout<<getValue(i,fenwick,siz/2-1)<<" ";
		}
		//cout<<endl;
		
	}
	
//	cout<<" AFTER UP "<<endl;
	


	ll maxv=0;	
	for(int i=0;i<siz/2;i++)
		{
		//cout<<getValue(i,fenwick,siz/2)<<" ";
		maxv=max(getValue(i,fenwick,siz/2),maxv);
		}
		//cout<<endl;
	cout<<maxv<<endl;
}
