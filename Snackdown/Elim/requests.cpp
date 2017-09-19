#include<bits/stdc++.h>
using namespace std;
#define L(i,n) for(int i=0;i<n;i++)
#define pi pair<int,int>

int brute(int ar[],int br[],int n)
{
queue<int> q;
for(int i=0;i<n;i++){
q.push(i);
}
int ProcessTime[n+1]={};
int t=1;
while(!q.empty())
	{
	int req=q.front();
	q.pop();
	if(br[req]<=t)
	{
	ProcessTime[req]=t+ar[req];
	t+=ar[req];
	}
	else
	{
	q.push(req);
	}	
	t++;
	}
for(int i=0;i<n;i++)
cout<<ProcessTime[i]<<" ";
cout<<endl;
}

int trial(int ar[],int br[],int n)
{
queue<int> q;
set<pi> qs;
for(int i=0;i<n;i++){
q.push(i);
qs.insert(pi(br[i],i));
}
int ProcessTime[n+1]={};
int t=1;
while(!q.empty())
	{
	int req=q.front();
	q.pop();
	cout<<"Tried "<<req<<"at t="<<t<<endl;
	if(br[req]<=t)
	{
	cout<<"completed "<<req<<" at "<<t+ar[req]<<endl;
	ProcessTime[req]=t+ar[req];
	qs.erase(pi(br[req],req));
	t+=ar[req];
	}
	else
	{
	int minw=(*(qs.begin())).first;
	int diff=(minw-t);
	t+=(diff/qs.size())*qs.size();
	cout<<"retry "<<req<<endl;
	q.push(req);
	}	
	t++;
	}
for(int i=0;i<n;i++)
cout<<ProcessTime[i]<<" ";
cout<<endl;
}

int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int ar[n],br[n];
L(i,n)cin>>ar[i];
L(i,n)cin>>br[i];
trial(ar,br,n);
}
}
