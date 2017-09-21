#include<stdio.h>

int insertSort(int ar[],int size)
{
	int i=0;//m=size;
	int swap=0;
	for(i=0;i<size;i++)
	{
		int j=i,val=ar[i];
		while(val<ar[j-1]&&j>0)
			{
			//	printf("HI");
				
				ar[j]=ar[j-1];
	                                                                                                                        

				j--;
				swap++;
			}
			ar[j]=val;
	}
	return swap;
		//printf("\n\ncomps=%d",swap);

}
int main()
{
	int i, ar[5000]={1, 3, 9, 8 ,2 ,7 ,5};
int n1;
scanf("%d",&n1);

	cout<<insertSort(ar,n1)<<"\n";
//	printf(" n=%d %d\n",n1);
	/*printf("\ncomps=%d",comps);
	int j1=Lpart(0,j,ar[j-1],ar);
		printf("\n\ncomps=%d",comps);
	Lpart(j+1,n,ar[j-1],ar);*/
	


	return 0;
}