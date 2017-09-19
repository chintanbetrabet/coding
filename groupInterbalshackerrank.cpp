#include<bits/stdc++.h>

#include<stdio.h>
using namespace std;
const int N = 112345;  // limit for array size
#define mp(i,j) pair<int,int>(i,j)
int n;  // array size
int votes[N];
pair<int,int> t[2 * N];
int x;
pair<int,int> max(pair<int,int> a,pair<int,int> b,int x)
{
	if((a.first) <=x && b.first <=x)
	{
	cout<<x<<" l1 COmparing "<<a.first<<","<<a.second<<" with "<<b.first<<","<<b.second<<endl;
	if(a.first>b.first)return a;
	if(a.first<b.first)return b;
	if(a.second<b.second)return a;
	return b;
	}
	else if((a.first) <=x || b.first <=x)
	{
		cout<<x<<" l2 COmparing "<<a.first<<","<<a.second<<" with "<<b.first<<","<<b.second<<endl;
		if(a.first>x)return b;
		if(b.first>x)return a;
		if(a.second<b.second)return a;
		return b;
	}
	else
	{
	cout<<x<<" l3 COmparing "<<a.first<<","<<a.second<<" with "<<b.first<<","<<b.second<<endl;
	return mp(x,1000000);
	}
}
void build(int x) {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1] , t[i<<1|1],x);
}
/*
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p] , t[p^1]);
}
*/
pair<int,int> query(int l, int r,int x) {  // sum on interval [l, r)
  pair<int,int> res = mp(x,10000);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++],x);
    if (r&1) res = max(res,t[--r],x);
  }
  return res;
}

int main() {
int T;
cin>>T;
while(T--)
{
  scanf("%d", &n);
  int v;
  for (int i = 0; i < n; ++i)votes[i]=0;
   for (int i = 0; i < n; ++i)
   {
   cin>>v;
   votes[v]++;
   }
  for (int i = 0; i < n; ++i)
  {
   t[n + i]=pair<int,int>(votes[i],i);
  }
  
  //modify(0, 1);
  int g;
  scanf("%d",&g);
  for(int i=0;i<g;i++)
  {
  int l,r,x;
  cin>>l>>r>>x;
  //x=100;
  build(x);
  for(int k=0;k<2*n;k++)
  {
  	cout<<"k:"<<k<<"  "<<t[k].first<<","<<t[k].second<<endl;
  }
  pair<int,int> a=query(l,r,x);
  cout<<a.first<<" "<<a.second<<endl;
  cout<<endl;
  //printf("%d\n", query(3, 11));
  }
}
  return 0;
}
