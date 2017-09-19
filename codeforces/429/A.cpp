#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
int ar[26]={};
string s;
cin>>s;
int fl=0;
for(int i=0;i<n;i++)
	{
		ar[s[i]-'a']++;
		if(ar[s[i]-'a']>k)
		{
		fl=1;
		break;
		}
	}
if(fl==0)cout<<"Yes\n";
else cout<<"No";
}
