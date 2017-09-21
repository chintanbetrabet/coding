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
	int b[40000];
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

int main()
{
	int n,t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{//int s=0;
	int minx=1000,maxx=-1000,miny=1000,maxy=-1000;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			int k;
			for(k=0;k<4;k++){
				int x,y;
			scanf("%d %d",&x,&y);
			if(x>maxx)maxx=x;
			if(x<minx)minx=x;
			if(y>maxy)maxy=y;
			if(y<miny)miny=y;
			
			}
		}
		
		printf("%d\n",((maxx-minx)*(maxy-miny)));
		
	}
}