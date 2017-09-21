#include<stdio.h>
#include<iostream>
using namespace std;
void show_facs(int n,int ar[])
{
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0){
		cout<<i<<"\n";
		ar[s++]=i;
		}
	}
	cout<<ar[s/2-1]<<" "<<ar[s/2]<<"  "<<ar[s/2+1];
}
main()
{
	int ar[100];
	show_facs(72,ar);
}