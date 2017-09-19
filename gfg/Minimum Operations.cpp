#include <bits/stdc++.h>
using namespace std;
#define mp(s1,s2) pair<int,int>(s1,s2)
int visit[10000];
bool isValid(int d1,int d2,int m,int n)
{
    if(d1 >= 0 && d1 <m)
    {
        if(d2>=0 && d2 <n)
        return true;
    }
    return false;
}
void push(int v1,int d,queue<pair<int,int> > &q)
{
if(v1< 10001&&visit[v1]==0)
	{
	q.push(mp(v1,d));
	}
if(v1< 10001)
visit[v1]=1;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    for(int i=0;i<10000;i++)visit[i]=0;
	    int s1;
	    cin>>s1;
	    queue<pair<int,int> >q;
	    q.push(mp(0,0));
	    int f=0;
	    while (!q.empty())
	    {
	        pair<int,int> node =q.front();q.pop();
	        int t1,dist1;
	        t1=node.first;
	        dist1=node.second;
	        if (t1==s1)
	        {
	            cout<<dist1<<endl;
	            f=1;
	            break;
	        }
	        push(t1+1,dist1+1,q);
	        push(t1*2,dist1+1,q);
	       		        
	    }
	    if(f==0)
	    cout<<"-1"<<endl;
	}
	return 0;
}
