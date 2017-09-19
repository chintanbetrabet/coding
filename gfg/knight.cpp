#include <bits/stdc++.h>
using namespace std;
#define mp(s1,s2,d) pair<pair<int,int>,int>(pair<int,int>(s1,s2),d)
int visit[25][25]={};
bool isValid(int d1,int d2,int m,int n)
{
    if(d1 >= 0 && d1 <m)
    {
        if(d2>=0 && d2 <n)
        return true;
    }
    return false;
}
void push(int v1,int v2,int d,queue<pair<pair<int,int>,int> > &q)
{
if(visit[v1][v2]==0)
	{
	q.push(mp(v1,v2,d));
	}
visit[v1][v2]=1;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    for(int i=0;i<25;i++)for(int j=0;j<25;j++)visit[i][j]=0;
	    vector<pair<int,int> >g[25][25];
	    int m,n;
	    cin>>m>>n;
	    int s1,s2,d1,d2;
	    cin>>s1>>s2>>d1>>d2;
	    s1--;
	    s2--;
	    d1--;
	    d2--;
	    queue<pair<pair<int,int>,int> > q;
	    q.push(mp(s1,s2,0));
	    int f=0;
	    while (!q.empty())
	    {
	        pair<pair<int,int>,int> node =q.front();q.pop();
	        int t1,t2,dist1;
	        t1=node.first.first;
	        t2=node.first.second;
	        dist1=node.second;
	        if (t1==d1 && t2==d2)
	        {
	            cout<<dist1<<endl;
	            f=1;
	            break;
	        }
	        if(isValid(t1+2,t2+1,m,n))push(t1+2,t2+1,dist1+1,q);
	        if(isValid(t1+2,t2-1,m,n))push(t1+2,t2-1,dist1+1,q);
	       	if(isValid(t1+1,t2+2,m,n))push(t1+1,t2+2,dist1+1,q);
	       	if(isValid(t1+1,t2-2,m,n))push(t1+1,t2-2,dist1+1,q);
	       	if(isValid(t1-2,t2+1,m,n))push(t1-2,t2+1,dist1+1,q);
	       	if(isValid(t1-2,t2-1,m,n))push(t1-2,t2-1,dist1+1,q);
	       	if(isValid(t1-1,t2+2,m,n))push(t1-1,t2+2,dist1+1,q);
	       	if(isValid(t1-1,t2-2,m,n))push(t1-1,t2-2,dist1+1,q);
			        
	    }
	    if(f==0)
	    cout<<"-1"<<endl;
	}
	return 0;
}
