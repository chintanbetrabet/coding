#include <bits/stdc++.h>
using namespace std;
int visit[112345];
int v=0;
#define mp(a,b) pair<int,int>(a,b)
#define loop(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
void dfs(vector<int>g[],int node,int target)
    {
    	//cout<<"traversed "<<node<<endl;
        if(node==target)v++;
        if(visit[node]==0)
        {
            visit[node]=1;
            for(int i=0;i<g[node].size();i++)dfs(g,g[node][i],target);
        }
    }
int main() {
	//code
	pair<int,int> dp[1000]={};
	dp[3]=mp(0,1);
	dp[5]=mp(1,0);
	dp[6]=mp(0,2);
	dp[8]=mp(1,1);
	dp[9]=mp(0,3);
	dp[10]=mp(2,0);
	for(int i=11;i<1000;i++)
	{
		if(dp[i-3].se > 0)
			{
			
			}
	}
	int t;
	cin>>t;
	while(t--)
	{
    int n;cin>>n;
    
	}
	return 0;
}
