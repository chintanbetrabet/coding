#include<bits/stdc++.h>
using namespace std;
long gcd(long a,long b)
{
//cout<<" got "<<a<<" "<<b<<endl;
if (a%b==0)
	{
	return b;
	}
else if(b%a==0)
	{
	return a;
	}
else 
	{	
		if(a>b)
		return gcd(b,a%b);
		else return gcd(a,b%a);
	}

}
void gcd_runner()
{
long t;
cin>>t;
while(t--)
	{
	long a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	}
}
int main()
{
long t;
cin>>t;
while(t--)
	{
long n;
vector<long> lcm_list;
cin>>n;
long ar[1000];
for(long i=0;i<n;i++)cin>>ar[i];
for(long i=0;i<n;i++)for(long j=i+1;j<n;j++)lcm_list.push_back(ar[i]*ar[j]/gcd(ar[i],ar[j]));
//for(long i=0;i<lcm_list.size();i++)cout<<lcm_list[i]<<" ";
sort(lcm_list.begin(),lcm_list.end());
cout<<lcm_list[0]<<endl;
	}
}
