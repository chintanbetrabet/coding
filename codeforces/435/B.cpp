#include<bits/stdc++.h>
using namespace std;
long long color[112345];
vector<long long> g[112345];
long long visited[112345];
void dfs(long long node)
{
if(visited[node])return;
visited[node]=1;
if(color[node]==-1)color[node]=1;
for(long long i=0;i<g[node].size();i++)
	{
	color[g[node][i]]=(color[node]^1);
	}
for(long long i=0;i<g[node].size();i++)
	{
	dfs(g[node][i]);
	}
}

int main()
{
long long n;cin>>n;
for(long long i=0;i<112345;i++)color[i]=-1;
for(long long i=0;i<n-1;i++)
	{
	long long u,v;
	cin>>u>>v;
	g[u].push_back(v);
	g[v].push_back(u);
	}
	dfs(1);
long long sum=0;
for(long long i=1;i<=n;i++)
	{
	//cout<<"i:"<<i<<" COl:"<<color[i]<<endl;
	sum+=color[i];
	}
long long ones=sum;
long long zeroes=n-ones;
long long addedNodes=1-n;
addedNodes+=ones*zeroes;
cout<<addedNodes;
	
}
