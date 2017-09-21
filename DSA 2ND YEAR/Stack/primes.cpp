#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int primes[1201];
void getPrimes(int q)
{
	int pr=0;
	primes[pr++]=2;
	int n=3;
	while(pr<q)
	{
		int valid=1;
	for(int i=3;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				valid=0;break;
			}
		}
		if(valid)
		primes[pr++]=n;
		n+=2;
	}
}
int main()
{
	int p;
	int q;
	cin>>p>>q;
	getPrimes(q);
vector<int>stack[q+5];vector<int>temps[q+5];
for(int i=0;i<p;i++)
	{
		int val;
		cin>>val;
		temps[0].push_back(val);
	}	

for(int i=0;i<q;i++)
	{
		//	cout<<"\nsize="<<temps[i].size();
		for(int j=0;temps[i].size()!=0;j++)
		{
			int x=temps[i].back();
			temps[i].pop_back();
			if(x%primes[i]==0){
			//	cout<<"\nPUSH "<<x<<" in S"<<i;
			stack[i].push_back(x);
			}
			else {
			//	cout<<"\nPUSH "<<x<<" in T"<<i;
				temps[i+1].push_back(x);
				}
		}
	}
for(int i=0;i<q;i++)
{
	for(int j=0;stack[i].size()!=0;j++){
		int x=stack[i].back();
			stack[i].pop_back();
			cout<<x<<"\n";
	}
}
for(int i=0;temps[q].size()!=0;i++)
{
		int x=temps[q].back();
			temps[q].pop_back();
			cout<<x<<"\n";
}
	
}