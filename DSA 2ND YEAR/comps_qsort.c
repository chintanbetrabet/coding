#include<stdio.h>
#include<conio.h>
int n,comps=0,call=0,swap=0;
void insertSort(int ar[],int size)
{
	int i=0;//m=size;
	//int swap=0;
	for(i=0;i<size;i++)
	{
		int j=i,val=ar[i];
		while(val<ar[j-1]&&j>0)
			{
			//	printf("HI");
				
				ar[j]=ar[j-1];
			/*	int k;
			for(k=0;k<size;k++)
			{
		printf("%d ",ar[k]);
			}*/
			//printf("\n");

				j--;
				swap++;
			}
			ar[j]=val;
	}
		//printf("\n\ncomps=%d",swap);

}

int Lpart(int first,int last,int val,int ar[])
{
	int i=first,j=0,c=0;
	while(i<last-1&&j<last-1)
	{
                                                                                                                        
		while(ar[i]<val&&i<last-1)
		{
			
			//printf(" \nswap : %d , %d ",ar[i],ar[i]);getch();
			c++;
			i++;
		}
		j=i;
		while(ar[j]>val&&j<last-1)j++;
		if(ar[i]>=ar[j]&&j<last-1){
			//printf(" \nswap : %d , %d ",ar[i],ar[j]);getch();
		int t=ar[i];
		ar[i]=ar[j];
		ar[j]=t;
		c++;i++;
		}
	}
	int t=ar[last-1];
	ar[last-1]=ar[i];
	ar[i]=t;c++;
int k;
	for(k=0;k<n;k++)
	{
		printf("%d ",ar[k]);
	}
	printf("    :%d\n",c);
	getch();
	comps+=c;
	return i;
}
void Qsort(int first,int last,int val,int ar[])
{
	if(last-first>1)
	{call++;
		int j=Lpart(first,last,val,ar);
		Qsort(first,j,ar[j-1],ar);
		Qsort(j+1,last,ar[last-1],ar);
	}
}
int main()
{
		int i,ar1[5000],ar2[5000];
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int v;
		scanf("%d",&v);
		ar1[i]=v;//ar2[i]=v;
	}
	Qsort(0,n,ar1[n-1],ar1);

	//insertSort(ar2,n);
	//	printf("n=%d ",n);
	//printf("%d",swap-comps);
		for(i=0;i<n;i++)
	{
		//int v;
	printf("%d ",ar1[i]);
		//ar1[i]=v;//ar2[i]=v;
	}

	return 0;
}