#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int color[MAX];
int visit[MAX];
int bipart=1;
int debug=1;
int dfs(int node,int g[MAX][MAX], int v)
{
	visit[node]=1;
	if(debug)
	cout<<"traversed "<<node<<" of color "<<color[node]<<endl;
		for(int i=0;i<v;i++)
			{
				if(g[node][i]==1)
				{
				    if(color[i]==0)
				    {
				        if(color[node]==1)color[i]=2;
				        else color[i]=1;
				        if(debug)
				        cout<<"ASSIGNED color"<<color[i]<<" to "<<i<<endl;
				    }
				    else
				    {
				    if(color[node]==color[i])bipart=0;
				    }
				if(visit[i]==0)
				    {
				    dfs(i,g,v);
				    }
				}
				
			}
	return 0;
}
bool isBipartite(int g[MAX][MAX], int v)
{
    for(int i=0;i<v;i++)color[i]=0;
    for(int i=0;i<v;i++)visit[i]=0;
    bipart=1;
    for(int i=0;i<v;i++)
    {
    	int outedges=0;
    	
    	for(int ed=0;ed<v;ed++)outedges+=g[i][ed];
        if(visit[i]==0&&outedges>0)
        {
            color[i]=1;
            dfs(i,g,v);
        }
    }
    for(int i=0;i<v;i++)
    {
        if(debug)
        cout<<"Color of "<<i<<" "<<color[i]<<endl;
    }
    
    return bipart;
    
}
int main()
{
int n,m;
int t;
cin>>t;
while(t--)
{
int g[1000][1000]={};
cin>>n>>m;
for(int i=0;i<m;i++)
	{
	int e1,e2;
	cin>>e1>>e2;
	g[e1][e2]=1;
	}
cout<<isBipartite(g,n)<<endl;
}

}




