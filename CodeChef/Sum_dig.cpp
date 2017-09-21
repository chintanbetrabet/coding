#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
int maxV=0;
int max_sub(int ar[],int &start,int &last)
{
	//int sum=ar[start];
	if(start==last-1){
		cout<<ar[start]<<"\n";
		int val=ar[start];
		if(ar[start]>maxV)maxV=ar[start];
		if(ar[start]<0)
		last=start;
	
	//else last=start;
	return val;
	}
	else {
		int sum=0;
		int s2,l2;
		int s1=start;
		int l1=s2=(start+last)/2;l2=last;
	
		int sum1=max_sub(ar,s1,l1);
		int sum2=max_sub(ar,s2,l2);
	
			for(int i=start;i<last;i++)
			{
				cout<<ar[i]<<" ";
			}
			printf("\ns1=%d,s2=%d,l1=%d,l2=%d\n",s1,s2,l1,l2);
			
		
			if(sum1+sum2>maxV){
				maxV=sum1+sum2;
				sum=sum1+sum2;
				start=s1;
				last=l2;
				cout<<"Merge SUM1"<<endl;
				}
			else if(s2==l1)
			{
				cout<<"Exceptional\n";
				last=l2-1;
				start=s1;
				int extra=0;
				for(int k=s2;k<l2;k++)
				extra+=ar[k];
				sum=sum1+extra;
				if(sum>maxV)maxV=sum;
				printf("sum1 =%d sum 2=%d sum=%d maxV=%d extra=%d",sum1,sum2,sum,maxV,extra);
			}
		
		else if(sum1>maxV)
		{
			start=s1;last=l1;
			maxV=sum1;
			sum=sum1;
			printf("startMax at %d ,end at %d ",start,last);
			cout<<"SUM1"<<endl;
		}
		else if(sum2>maxV)
		{
			start=s2;last=l2;
			maxV=sum2;
			sum=sum1;
			cout<<"SUM2"<<endl;
		}
		else cout<<"NONNONONONONONONONOONONON\n";
			cout<<"maxV="<<maxV;
			
			printf("\nStart=%d end=%d\n",start,last);
			cout<<"sum1="<<sum1<<" sum2= "<<sum2<<" sum= "<<sum<<"\n";getch();
			
			return sum;
		}
	
}

int main()
{
	int ar[]={1,2,30,-15,4000,0,-500,1000};
	int star=0,las=sizeof(ar)/4;
	printf("\nsum=%u ",max_sub(ar,star,las));
	cout<<"maxV="<<maxV;
	return 0;
}