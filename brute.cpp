#include<iostream>
#include<string>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
        {
int n;cin>>n;
int s=0;
for(int i=1;i<n;i++)
	if(n%i==0)s+=i;
cout<<s<<endl;
        }
}
