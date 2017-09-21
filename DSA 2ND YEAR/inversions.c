#include<stdio.h>
//int comps=0;
long  long unsigned int invs=0;
int compare(long long v1,long long v2)
{
	//comps++;
	if(v1>v2)
	return 1;
	else if(v2>v1)
	return -1;
	else return 0;
}
void sortMerger(long long unsigned int first,long long unsigned int last,long long unsigned int A[])
{long  long int linvs=0;
    long long unsigned int mid=(first+last)/2;
	;long long unsigned int  b[100000];
   /*printf("\nhalf 1:");
    int c1;
    for(c1=first;c1<mid;c1++)
        printf("%d ",A[c1]);
      printf("\nhalf 2:");
    
    for(c1=mid;c1<last;c1++)
        printf("%d ",A[c1]);*/
	long long unsigned int size=0;;
    
	long long unsigned int i=first,j=(first+last)/2;
	while(i<mid&&j<last)
	{//printf(" AI=%d AJ=%d",A[i],A[j]);
		if(compare(A[i],A[j])==1)
            {
            //printf("\nup linvs up by: %d for %d",mid-i,A[i]);
            linvs+=mid-i;         
            b[size++]=A[j++];
        }
		else
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
void MergeSort(long long unsigned int first,long long unsigned int last,long long unsigned int a[])
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
   int t;
    scanf("%d",&t);
    for(int x=0;x<t;x++){
	long long unsigned int a[100000],i,n;
    scanf("%llu",&n);
    scanf("\n");
    for(i=0;i<n;i++)
    scanf("%llu",&a[i]);
	MergeSort(0,n,a);
    //if(invs<=4049955000)
    //printf("%llu\n",invs);
        //else{
            long long unsigned max=(n)*(n-1);
            printf("%llu\n",max);
            //}
    invs=0;
    }
    return 0;
    int i,v;
    scanf("%d",&v);
    printf("1 %d ",v);
    for(i=v;i>0;i--)
    printf("%d ",i);
	
}