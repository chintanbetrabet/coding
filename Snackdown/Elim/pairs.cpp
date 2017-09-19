#include<bits/stdc++.h>
using namespace std;
#define L(i,n) for(int i=0;i<n;i++)
#define pi pair<int,int>

vector<pi> gedges;
vector<pi> getedges(int m,int n,int C[],int D[],int e,int x)
{
gedges.clear();
set<pi> seted;
L(i,n)L(j,m)
		{
		if(abs((C[i]+x)-D[j])<=e)
			{
			seted.insert(make_pair((C[i]+x),D[j]));
			}
		}
gedges.clear();
for(set<pi> ::iterator it=seted.begin();it!=seted.end();++it)
{
gedges.push_back(*it);
}
return gedges;
}

bool notIn(set<int> marked,int val)
{
return marked.find(val)==marked.end();
}

int maxmatch(vector<pi> edges)
{
set<int> marked;
int cnt=0;

//cout<<"size ="<<edges.size()<<endl;
for(int i=0;i<edges.size();i++)
	{
	int e1=edges[i].first;
	int e2=edges[i].second;
		if(marked.find(e1)==marked.end()&&marked.find(e2)==marked.end())
		{
		cnt+=1;
		marked.insert(e1);
		marked.insert(e2);
		}
	}
return cnt;
}
int main()
{
vector< pi> edges;
int t;
cin>>t;
while(t--)
	{
	int n,m,e,x;
	cin>>n>>m>>e;
	int C[n],D[m];
	L(i,n)cin>>C[i];
	L(i,m) cin>>D[i];
	L(i,n)cout<<C[i]<<" ";
	cout<<endl;
	L(i,m)cout<<D[i]<<" ";
	cout<<endl;
	x=0;
	int mm=0;
	int cx=-10000000;
	int siz=max(11000+e,abs(8-e));;
	for(int x=-1*siz;x<siz;x++)
	{
	edges=getedges(m,n,C,D,e,x);
	//cout<<x<<","<<" edges="<<edges.size()<<endl;
	//	L(k,edges.size())cout<<"["<<(edges[k].first+x)<<","<<edges[k].second<<"]";
		
	int cmax=maxmatch(edges);
	if(cmax>0)
	cout<<x<<"  "<<cmax<<endl;
	if(cmax>mm)
		{
		cx=x;
		mm=cmax;
		}
		
	
	
	}
	cout<<"MaX="<<mm<<"  "<<cx<<endl;	
	}

}
