#include<bits/stdc++.h>
using namespace std;
int isStack[112345];
int visit[112345];
int partOfcycle[112345];
vector<int> g[112345];
int startCycle=-1;
void printCycle(int node)
{
	if(visit[node]==0)
	{
	cout<<node<<" ";
	visit[node]=1;
		for(int i=0;i<g[node].size();i++)
			{
				if(partOfcycle[g[node][i]]==1)
					{
					printCycle(g[node][i]);
					}
			}
	}
}
int dfs(int node)
{
	visit[node]=1;
		for(int i=0;i<g[node].size();i++)
			{
				if(visit[g[node][i]]==1 && isStack[g[node][i]]==1)
				{
				partOfcycle[g[node][i]]=1;
				partOfcycle[node]=1;
				startCycle=g[node][i];
				return 1;
				}
				else if(visit[g[node][i]]==0)
				{
				isStack[g[node][i]]=1;
				int rv=dfs(g[node][i]);
					if(rv==1)
						{
						partOfcycle[node]=1;
						return 1;
						}
				}
			}
	isStack[node]=0;
	return 0;
}

int main()
{
string line;
int t,n,m;
t=1;
while(t--)
{
cin>>n>>m;
while (m--)
{
    int e1,e2;
    cin>>e1>>e2;
    g[e1].push_back(e2);
}
int i;
for(int i=0;i<1;i++)
{
isStack[i]=1;
dfs(i);
}
for(int i=0;i<n;i++)
{
visit[i]=0;
}
if(startCycle!=-1)
	{
	printCycle(startCycle);
	}
else
{
cout<<-1<<endl;
}	
}	
}
