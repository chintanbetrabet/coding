#include<bits/stdc++.h>
using namespace std;
#define ll int
ll lessThanEqualIndex(vector<ll> v,ll val)
{
return lower_bound(v.begin(),v.end(),val)-v.begin();
}
ll greaterThanEqual(vector<ll> &v,ll val)
{
return upper_bound(v.begin(),v.end(),val)-v.begin();
}
int main()
{
ll n,q;
cin>>n>>q;
vector<ll> times(n),prices(n);
for(ll i=0;i<n;i++)cin>>times[i];
for(ll i=0;i<n;i++)cin>>prices[i];

vector<ll>  lmax(n),rmax(n);
rmax[0]=prices[0];
lmax[n-1]=prices[n-1];
for(ll i=1;i<n;i++){rmax[i]=max(rmax[i-1],prices[i]);}
for(ll i1=n-2;i1>=0;i1--){lmax[i1]=max(lmax[i1+1],prices[i1]);}

while(q--)
	{
	ll qt,qv;
	cin>>qt>>qv;
	//cout<<"Q:"<<qt<<" "<<qv<<endl;
	switch(qt)
	{
	case 1: {
		ll ind=lessThanEqualIndex(rmax,qv);
		if(ind!=n)
			{
			cout<<times[ind]<<endl;
			}
		else
		{
		cout<<"-1\n";
		}
		break;
		}
	case 2: {
		ll ind=greaterThanEqual(times,qv);
		if(ind!=n)
		{
		cout<<lmax[ind]<<endl;
		}
		else{
		cout<<"-1\n";
		}
		break;
		}
	}
	
	
	}
}

