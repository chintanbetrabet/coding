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
	int ar1[last-first+1],size1=0;
	int ar2[last-first+1],size2=0,i;
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
	/*if(size1>1){
for(i=0;i<size1;i++)
			printf("(1)%d ",ar1[i]);
			printf("\n");
		}*/
	for(i=0;i<eq;i++)
	ar[size1+first+i]=val;
		
		//	printf(" copied till %d\n",size1+first+eq-1);*/
			
	for(i=0;i<size2;i++)
	ar[i+size1+1+first+eq-1]=ar2[i];
/*	if(size2>1){
		for(i=0;i<size2;i++)
			printf("(2)%d ",ar2[i]);
			printf("\n");
			}
		//	getch();*/
	return first+size1+1;
}
void Qsort(int first,int last,int val,int ar[],char side='l')
{
	//	printf("YOLO");
	if(first<last-2)
	{int i;

			
			int j=partition(first,last,ar[first],ar);
			
		if(side=='l')
			Qsort(first,j,ar[first],ar,'l');
		else Qsort(first,j,ar[first],ar,'r');
			i=first;
	
		if(j-first>2&&side=='l'){
			//printf("PIV:%d",val);
		while(ar[i]<val)
		{
			printf("%d ",ar[i]); i++;
		}
			printf("\n");
		}
	
		i++;
		
		Qsort(j,last,ar[j],ar,'r');
		if(last-j>2&&side=='l'){
		//	printf("PIV:%d",val);
		while(i<last-1)
		{
			printf("%d ",ar[i]); i++;
		}	printf("\n");
		}



	}
else	if(first==last-2)
	{
	//	printf("\nYO Piv=%d\n",val);
		if(ar[first]>ar[last-1]){
		int t=ar[first];
		ar[first]=ar[last-1];
		ar[last-1]=t;
		}
	if(side=='l')
	printf("(4)%d %d\n",ar[first],ar[last-1]);
	}
}
void qsort(int first,int last,int val,int ar[])
{
	if(first<last-2)
	{int i;

			
			int j=partition(first,last,ar[first],ar);
			

		Qsort(first,j,ar[first],ar,'l');
	if(j-first>2){
			//printf("PIV:%d",val);
			i=0;
		while(ar[i]<val&&i<last)
		{
			printf("%d ",ar[i]); i++;
		}	printf("\n");
		}

		i++;
		Qsort(j,last,ar[j],ar,'r');
			if(last-j>2){
			//printf("PIV:%d",val);
			
		while(i<last)
		{
			printf("%d ",ar[i]); i++;
		}	printf("\n");
		}


	}
else	if(first==last-2)
	{
		printf("\nYO Piv=%d\n",val);
		if(ar[first]>ar[last-1]){
		int t=ar[first];
		ar[first]=ar[last-1];
		ar[last-1]=t;
		}
	//	if(side=='l')
	printf("%d %d\n",ar[first],ar[last-1]);
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
qsort(0,size,ar[0],ar);	
	for(i=0;i<size;i++)
	printf("%d ",ar[i]);
	printf("\n");
	}
	return 0;
	
}