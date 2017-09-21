#include<stdio.h>
#include<math.h>
long long invs=0;
int bins(int up,int down,int ar[],int val,int size) //find last occurence
    {
	    //printf("call on :%d to %d",up,down);
    if(ar[(up+down)/2]==val)
        {
        int mid=(up+down)/2;
        while(mid+1<size&&ar[mid+1]==val)mid++;
        return mid;
    }
    else if(up==down)
        return -1;
    else if(val<ar[(up+down)/2])
        return bins(up,(up+down)/2,ar,val,size);
    else return bins((up+down)/2+1,down,ar,val,size);
}
int bins(int up,int down,int ar[],int val) //find only occurence
    {
	    printf("call on :%d to %d",up,down);getch();
	    if(up>down){
    if(ar[(up+down)/2]==val)
        {
        int mid=(up+down)/2;
        return mid;
    }
    else if(up==down)
        return -1;
    else if(val<ar[(up+down)/2])
        return bins(up,(up+down)/2+1,ar,val);
    else return bins((up+down)/2-1,down,ar,val);
    }
    else return -1;
}
int compare(long long v1,long long v2)
{
	//comps++;
	if(v1>v2)
	return 1;
	else if(v2>v1)
	return -1;
	else return 0;
}
void sortMerger(int first,int last,int A[])
{int linvs=0;
    int mid=(first+last)/2;
	;long long b[100000];
   /*printf("\nhalf 1:");
    int c1;
    for(c1=first;c1<mid;c1++)
        printf("%d ",A[c1]);
      printf("\nhalf 2:");
    
    for(c1=mid;c1<last;c1++)
        printf("%d ",A[c1]);*/
	long long size=0;;
    
	int i=first,j=(first+last)/2;
	while(i<(first+last)/2&&j<last)
	{
		if(compare(A[i],A[j])==1)
            {
            //printf("\nup linvs up by: %d for %d",j-mid+1,A[i]);
            linvs+=mid-i;
            
            
        }
		
		b[size++]=A[i++];
	}
	while(i<(first+last)/2){
        //printf("\nlt linvs up by: %d for %d",last-mid,A[i]);
       // linvs+=last-mid;
        //printf("Ai=%d i=%d first=%d llast=%d ",A[i],i,first,last);
	b[size++]=A[i++];
}
	while(j<last)
		b[size++]=A[j++];
	
	for(i=0;i<size;i++)
	{
		A[first+i]=b[i];
	}
 //printf("\n local invs=%d\n",linvs);
 invs+=linvs;
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
            //k+=abs(j-bin_search(a,0,n,b[j],j));
        }
        printf("%d\n",k);
        
    }

//	printf("\ncomparisons=%d",comps);
}