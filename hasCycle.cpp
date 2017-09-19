#include<bits/stdc++.h>
using namespace std;
vector<int> g[112345];
int visited[112345];
int cycle[112345];
void dfs(int node,int source)
	{
	visited[node]=1;
	for(int i=0;i<g[node].size();i++)
		{
		if(g[node][i]==source)
			{
			cycle[g[node][i]]=1;
			return;
			}
		if(visited[g[node][i]]==0)
			{
			
			dfs(g[node][i],source);
			}
		}
	}
int main()
{
int m,n;
cin>>n>>m;
	for(int i=0;i<m;i++)
	{
	int u,v;
	cin>>u>>v;
	g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
		 visited[j]=0;
		}
	dfs(i,i);	
	}
	for(int k=1;k<=n;k++)
	{
		cout<<cycle[k]<<" ";
	}
	cout<<endl;
	
}
