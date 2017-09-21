#include<stdio.h>
int n;
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
int bins(int up,int down,int ar[],int val)
    {
	  int mid=(up+down)/2;
       if(up==down){
           if(ar[mid]!=val)return -1;
           else {
               while(ar[mid]==val)mid--;
               return mid;
           }
       }
	  else if(ar[mid]>val)
          return bins(mid,down,ar,val);
    else if(ar[mid]<val)return bins(up,mid,ar,val);
        else if(ar[mid]==val)
      {
          while(ar[mid-1]==val)mid--;
               return mid;
        
    }
  
    
	 
	 return -1 ;
}
int main()
{
    int t,i,m,ar[10000],sort[10000]={};
    scanf("%d",&t);
    for(i=0;i<t;i++)
        {
        //printf("hi");
        scanf("%d",&m);
        scanf("%d",&n);
        int j;
        for(j=0;j<n;j++){scanf("%d",&ar[j]);sort[ar[j]]++;}
       
        //for(j=0;j<n;j++){printf("%d ",ar[j]);b[j]=ar[j];}
        //printf("\n val=%d",m);
        int flag=0;
        for(j=0;j<n&&flag==0;j++)
            {
            int find=m-ar[j];
            if(find>=2)
                {
                    if(find!=ar[j])
                        {
                        int i1=-1;
                        if(sort[find]>0)
                            {
                            int s=0;
                            for(s=0;s<n;s++)
                                {
                                if(ar[s]==find){
	                                //printf(" YO1 ");
                                    i1=s;flag=1;break;
                                }
                            }
                            if(i1!=-1)
                             printf("%d %d \n",j+1,i1+1);
                        }
                            
                    }
                else if(sort[find]>1)
                    {int i1=-1,s;
                    for(s=0;s<n;s++)
                                {
                                if(ar[s]==find&&s>j){
	                               // printf(" YO2 ");
                                    i1=s;flag=1;break;
                                }
                            }
                            if(i1!=-1)
                             printf("%d %d \n",j+1,i1+1);
                    
                }
                   
                
            }
        }
      
    }
}