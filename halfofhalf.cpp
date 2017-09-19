#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
        {
int n;cin>>n;
int s=0;
if(n>1)s=1;
//cout<<"start s at :" <<s<<endl;
for(int i=2;i<sqrt(n);i++)
	if(n%i==0)
	{
//cout<<"i:"<<i<<endl;
	s+=i+n/i;
	}
if(sqrt(n)==int(sqrt(n))&&n>sqrt(n))
s+=sqrt(n);
//cout<<"val="<<n<<" , "<<sqrt(n)<<endl;//-int(sqrt(n));
cout<<s<<endl;
        }
}
