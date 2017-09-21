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
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
	MergeSort(0,n,a);
    long max_ar[n],max_no=0,maxV=a[1]-a[0];
for(i=2;i<n;i++)
    {
	    //printf("\nat i=%d diff= %d min=%d noi=%d at%d",i,a[i]-a[i-1],maxV,max_no,max_ar[max_no]);
    if(a[i]-a[i-1]<maxV){
        
        maxV=a[i]-a[i-1];
        max_ar[0]=i;
        max_no=1;
    }
    else if(a[i]-a[i-1]==maxV)
        {
        max_ar[max_no++]=i;
    }
}
for(i=0;i<max_no;i++)
printf("%d %d",a[max_ar[i]-1],a[max_ar[i]]);
return 0;
//	printf("\ncomparisons=%d",comps);
}