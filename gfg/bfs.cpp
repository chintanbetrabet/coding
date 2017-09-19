#include <bits/stdc++.h>
using namespace std;

#define mp(a,b) pair<int,int>(a,b)
#define fi first
#define se second
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    vector<int> g[112345];
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)cin>>ar[i];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=1;j<ar[i];j++)
	        {
	            g[i].push_back(i+j);
	        }
	    }
	    queue<pair<int,int> >q;
	    int f=0;
	    q.push(mp(0,0));
	    while(!q.empty())
	    {
            pair<int,int> node=q.front();
            q.pop();
            int pos=node.fi;
            int cost=node.se;
            for(int n1=0;n1<g[pos].size();n1++)
            {
                q.push(mp(g[pos][n1],cost+1));
            }
	    }
	}
	return 0;
}
