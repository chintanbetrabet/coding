#include<iostream>
#include<stdio.h>
//#include<conio.h>
using namespace std;
int n;
long long int sop=0;
int Lpart(int first,int last,int val,int ar[])
{
   
    sop+=val;
   cout<<"\npiv="<<val<<" f= "<<first<<" l= "<<last<<" sop= "<<sop;
	int i=first,j=0;
	while(i<last-1&&j<last-1&&i>j)
	{
		
	//printf("\ni=%d j=%d ",i,j);
	//	int k;
	/*	for(k=0;k<7;k++)
	{
		printf("%d ",ar[k]);
	}//getch();*/
		while(ar[i]<val&&i<last-1)i++;
		j=i;
		while(ar[j]>val&&j<last-1)j++;
		if(ar[i]>ar[j]&&j<last-1){
			//printf(" swap : %d , %d ",ar[i],ar[j]);getch();
		int t=ar[i];
		ar[i]=ar[j];
		ar[j]=t;
		}
	}
	int t=ar[last-1];
	ar[last-1]=ar[i];
	ar[i]=t;
	int k;
	/*for(k=0;k<n;k++)
	{
		printf("%d ",ar[k]);
	}
	printf("\n");*/
	return i;
}
void Qsort(int first,int last,int val,int ar[],int k)
{
    //sop+=val;
    cout<<" \nfirst = "<<first<<" last = "<<last;
	if(last-first>1)
	{
		cout<<" HI "<<val;;
		int j=Lpart(first,last,val,ar);
        if(j-1>k)
		Qsort(first,j,ar[j-1],ar,k);
        else if(j-1<k)
		Qsort(j+1,last,ar[last-1],ar,k);
            
	}
}
int main()
{
	int i,ar[112345];//={1 ,3 ,9 ,8 ,2 ,7 ,5};
	//n=7;
    int k;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
    //sop=ar[n-1];
	Qsort(0,n,ar[n-1],ar,k);
    cout<<"\n"<<sop;
	//printf("%llu",sop);

	return 0;
}