#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
#define mp make_pair 
int sets[112345];
int size[112345];
void initialize_set()
{
	for(int i=0;i<112345;i++)
	{
		sets[i]=i;
		size[i]=1;
	}
}
int findroot(int a)
{
	int i=a;
	while(sets[i]!=i)
	{
	i=sets[i];
	}
	return i;
}
void union_set(int a,int b)
{
	if(size[a]>size[b])
	{
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
		sets[findroot(a)]=findroot(b);
	}	
}

bool find(int a,int b)
{
	return findroot(a)==findroot(b);
}
int main()
{

int t;
cin>>t;
while(t--)
	{
	initialize_set();
	int n,m;
	cin>>n>>m;
	int deg[n+1]={};
	for(int i=0;i<n+1;i++)deg[i]=0;
	set<int> g[n+1];
	for(int i=0;i<m;i++)
		{
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		g[u].insert(v);
		g[v].insert(u);
		}
	//for(int i=0;i<n+1;i++)cout<<deg[i]<<endl;
	priority_queue<pair<pi,pi> > edges;
	for(int i=1;i<=n;i++)
	{
		set<int> :: iterator it;
		for(it=g[i].begin();it!=g[i].end();it++)
			{
			edges.push(mp(mp(min(deg[i],deg[*it]),max(deg[i],deg[*it])),mp(min(i,*it),max(i,*it))));
			}
	}
	
	int toAdd[n];
	int lastToadd=n-1;
	int lastInd=n;
	int components=n;
	int smallerDeg=n;
	while(!edges.empty())
	{
	
	pair<pi,pi> edgeDesc=edges.top();
	edges.pop();
	pi degDesc=edgeDesc.first;
	pi ep=edgeDesc.second;
	
	smallerDeg=degDesc.first;
	if(smallerDeg<lastInd)
		{
		for(int i=lastInd;i>=smallerDeg;i--)
			toAdd[i]=lastToadd;
		lastToadd=components-1;
		lastInd=smallerDeg;
		}
	else
		{
		if(!find(ep.first,ep.second))
			{
			union_set(ep.first,ep.second);
			components--;
			}
		
		}
	}
	toAdd[lastInd]=lastToadd;
	for(int i=lastInd-1;i>=0;i--)
			toAdd[i]=0;
	
	
	for(int i=0;i<n;i++)cout<<toAdd[i]<<" ";
	}
}

