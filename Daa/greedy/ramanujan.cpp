#include<bits/stdc++.h>
using namespace std;

int getmaxfac(unsigned long long n)
{
for(int i=9;i>=1;i--)
	{
		if(n%i==0)return i;
	}
}
int main()
{
int t;
cin>>t;
while(t--)
	{
	unsigned long long int n;
	cin>>n;
	int d=0;
	int nums[5000];
	if(n<10)
		{
		cout<<"1"<<n<<endl;
		}
	else{
	int nextnumt=getmaxfac(n);
	if(nextnumt==1){cout<<-1<<endl;continue;}
	while(n>1)
		{
	int nextnum=getmaxfac(n);
		nums[d]=nextnum;
		n/=nextnum;
		d++;
		}
	for(int i=d-1;i>=0;i--)
		{
		cout<<nums[i];
		}
	cout<<endl;
	}
	
	}

}
