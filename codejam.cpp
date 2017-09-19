#include<bits/stdc++.h>
using namespace std;
const int N = 112345;  // limit for array size
int n=N;  // array size
int t[26][2 * N];

void build(int ind) {  // build the tree
  for (int i = n - 1; i > 0; --i) t[ind][i] = t[ind][i<<1] + t[ind][i<<1|1];
}

void modify(int p, int value,int ind) {  // set value at position p
  for (t[ind][p += n] = value; p > 1; p >>= 1) t[ind][p>>1] = t[ind][p] + t[ind][p^1];
}

int query(int l, int r,int ind) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[ind][l++];
    if (r&1) res += t[ind][--r];
  }
  return res;
}

int main() {
char str[N];
int n,q;
cin>>n>>q>>str;

for(int i=0;str[i]>0;i++)
	{
		for(int j=0;j<26;j++)
			{
			if(str[i]=='a'+j)
				{
				t[j][N+i]=1;
				}
			else
				{
				t[j][N+i]=0;
				}
			}
	}
for(int i=0;i<26;i++)
  build(i);
for(int i=0;i<q;i++)
{
int p1,p2,p3;
char p3_1;
cin>>p1>>p2;
if(p1==1)
	{
		cin>>p3_1;
		modify(p2-1,0,str[p2-1]-'a');
		modify(p2-1,1,p3_1-'a');
		str[p2-1]=p3_1;
	}
else
{
cin>>p3;
	int flag=0;
	for(int x=0;x<26;x++)
	{
		flag+=query(p2-1,p3,x)%2;
		//cout<<" count of "<<char(('a'+x))<<" = "<<query(p2-1,p3,x)<<endl;
	}
if(flag < 2)
	{
	cout<<"yes\n";
	}
else
	{
	cout<<"no\n";
	}
}

}
  return 0;

}
