#include<iostream.h>
#include<map>
using namespace std;
long nc2(int n)
{
	return (n*(n-1))/2;
}
int main()
{
	int n;

	cin>>n;
	int dl[2000000]={},dr[2000000]={};
	for (int i=0;i<n;i++)
	{
		int r,c;
		cin>>r>>c;
		dl[c-r+n-1]++;
		dr[r-c+n-1]++;
	}
	long long int s=0;
	for(int j=0;j<2000000;j++)
	{
		s+=nc2(dl[j]);
		s+=nc2(dr[j]);
	}
	cout<<s;
	
}