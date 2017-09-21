#include<stdio.h>
//int size;
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
int partition(int first,int last,int val,int ar[])
{
	int ar1[last-first],size1=0;
	int ar2[last-first],size2=0,i;
	int eq=0;//printf("PIVOT:%d\n",val);
	for(i=first;i<last;i++)
	{
		if(ar[i]>val)
		ar2[size2++]=ar[i];
		else if(ar[i]<val)ar1[size1++]=ar[i];
		else eq++;
	}
	for(i=0;i<size1;i++)
	ar[i+first]=ar1[i];
	/*	for(i=0;i<size;i++)
			printf("(1)%d ",ar[i]);
			printf("\n");*/
	for(i=0;i<eq;i++)
	ar[size1+first+i]=val;
		/*for(i=0;i<size;i++)
			printf("%d ",ar[i]);
		//	printf(" copied till %d\n",size1+first+eq-1);*/
			
	for(i=0;i<size2;i++)
	ar[i+size1+1+first+eq-1]=ar2[i];
		/*for(i=0;i<size;i++)
			printf("%d ",ar[i]);
			printf("\n");
			getch();*/
			//if(last-first>2)
		//	{
				for(i=first;i<last;i++)
				printf("%d ",ar[i]);
				printf("\n");
			//}
	return first+size1+eq/2;
}
void Qsort(int first,int last,int val,int ar[])
{
	if(first<last-1)
	{int yes=1;
	/*for(i=first;i<last-1;i++)
	if(ar[i]>ar[i+1])
	{
		yes=1;break;
	}*/
			if(yes){
			int	j=partition(first,last,ar[(first+last)/2],ar);
	//printf("  First:%d Last:%d j=%d",first,last,j);printf("\n");	getch();
		//if(j!=first)
		Qsort(first,j,ar[(first+j)/2],ar);
	//	if(j!=last-1)
		Qsort(j,last,ar[(j+last-1)/2],ar);	
		}	
	}
}
int main()
{
	int t=1,ar[10000],size;
	//scanf("%d",&t);
	//printf("X is : %d\n",x);
	
    int i,k;
    for(k=0;k<t;k++){
    //size=sizeof(ar)/4;
		scanf("%d",&size);
		int j;
	for(j=0;j<size;j++)
		scanf("%d",&ar[j]);
		printf("\naround:%d\n",ar[size/2+1]); 
partition(0,size,ar[size/2+1],ar);	
	for(i=0;i<size;i++)
	printf("%d ",ar[i]);
	printf("\n");
	}
return 0;	
	
}