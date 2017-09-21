#include<stdio.h>
void merge2(int f1,int l1,int a[],int f2,int l2,int b[],int c[])
{
	int i=f1,j=f2,size=0;
	while(i<l1&&j<l2)
	{
		if(a[i]<b[j])
		c[size++]=a[i++];
		else c[size++]=b[j++];
	}
	while(i<l1)c[size++]=a[i++];
	while(j<l2) c[size++]=b[j++];
}
void partition(int first,int last,int val,int ar[])
{
	int ar1[last-first],size1=0;
	int ar2[last-first],size2=0,i;
	for(i=first;i<last;i++)
	{
		if(ar[i]>val)
		ar2[size2++]=ar[i];
		else if(ar[i]<val)ar1[size1++]=ar[i];
	}
	for(i=0;i<size1;i++)
	ar[i]=ar1[i];
	ar[size1]=val;
	for(i=0;i<size2;i++)
	ar[i+size1+1]=ar2[i];
	
	
}
void main()
{
	int ar[]={4,3,5,6,2};unsigned int i;
	partition(0,sizeof(ar)/4,ar[0],ar);
	for(i=0;i<sizeof(ar)/4;i++)
	printf("%d",ar[i]);
	
	
}