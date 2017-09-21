#include<stdio.h>

int compare(int v1,int v2)
{

	if(v1>v2)
	return 1;
	else if(v2>v1)
	return -1;
	else return 0;
}
void sortMerger(int first,int last,int A[])
{
	int b[last-first];
	int size=0;;
	int i=first,j=(first+last)/2;
	while(i<(first+last)/2&&j<last)
	{
		if(compare(A[i],A[j])==1)
		b[size++]=A[j++];
		else
		b[size++]=A[i++];
	}
	while(i<(first+last)/2)
	b[size++]=A[i++];
	while(j<last)
		b[size++]=A[j++];
	
	for(i=0;i<size;i++)
	{
		A[first+i]=b[i];
	}
}
void MergeSort(int first,int last,int a[])
{
	//printf("\nf=%d l=%d",first,last);
	if(first<last-1)
	{
		MergeSort(first,(first+last)/2,a);
		MergeSort((first+last)/2,last,a);
		sortMerger(first,last,a);		
	}
}
void main()
{
	int a[]={4,0,6,2,5,1,7,3},i;
	MergeSort(0,sizeof(a)/4,a);
for(i=0;i<sizeof(a)/4;i++)
printf(" %d ",a[i]);
//	printf("\ncomparisons=%d",comps);
}