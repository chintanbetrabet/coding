#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
	{
	int ar[100]= {} ;
	int n,s,sum=0;
cin>>n;
	for(int i=0;i<n;i++)
		{
		cin>>s;
		sum+=s;
		}
	if(sum%2==0)
		cout<<"Yes\n";
	else
		cout<<"No\n";	
	
	}
}

