#include<stdio.h>
#include<math.h>
long long invs=0;
int bins(int up,int down,int ar[],int val,int size)
    {
	    //printf("call on :%d to %d",up,down);
    if(ar[(up+down)/2]==val)
        {
        int mid=(up+down)/2;
        //while(mid+1<size&&ar[mid+1]==val)mid++;
        return mid;
    }
    else if(up==down)
        return -1;
    else if(val<ar[(up+down)/2])
        return bins(up,(up+down)/2,ar,val,size);
    else return bins((up+down)/2+1,down,ar,val,size);
}
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
	int a[100000],b[100000],i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        {
        int n,k=0;
        scanf("%d",&n);
        int j;
        for(j=0;j<n;j++)
            {
            scanf("%d",&a[j]);
            b[j]=a[j];
        }
        MergeSort(0,n,a);
       for(j=0;j<n;j++)
            {
            printf("%d ",a[j]);
        }
        printf("\n");
          for(j=0;j<n;j++)
            {
            printf("%d ",b[j]);
        }
        printf("\n");
           for(j=0;j<n;j++)
            {
            int v=bins(0,n,a,b[j],n);
            int curr_diff=abs(j-v);
            //if(abs(j-v-1)>abs(j-v+1)
          //  {
	           int delta=1;
	           printf("for:%d cd=%d",b[j],curr_diff);
	            while(v+delta<n&&a[v+delta]==b[j])
	            	{
		            	
		            	printf("comp to A[%d+%d]=%d cd(p)=%d\t",v,delta,a[v+delta],abs(j-v+delta));
		            	
		            	if(abs(j-v-delta)<curr_diff)
		            	curr_diff=abs(j-v-delta);
		            	delta++;
		            }
		            delta=1;
		             while(v-delta>=0&&a[v-delta]==b[j])
	            	{
		            	
		            	printf("comp A[%d-%d]=%d\t  cd(p)=%d ",v,delta,a[v-delta],abs(j-v-delta));
		            	if(abs(j-v+delta)<curr_diff)
		            	curr_diff=abs(j-v+delta);
		            	delta++;
		            }
		            printf("%d\n ",curr_diff);
	        // }
	         
        }
        printf("\n\n\n");
        
        
    }

//	printf("\ncomparisons=%d",comps);
}