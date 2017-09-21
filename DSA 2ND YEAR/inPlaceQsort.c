#include<stdio.h>
//#include<conio.h>
int size,swap=0;
int part(int first,int last,int val,int ar[])
{
	int i=first;
	int j=last-1;
	int pos;
	if(first<last-1){
	while(1==1)
	{
		
		while(ar[i]<val&&i<last){
			i++;
			}
		while(ar[j]>=val&&j>first){
		
			if(ar[j]==val)pos=j;
			j--;
		}
	if(i==j)	
	{
				int t =ar[pos];
		ar[pos]=ar[i];
		ar[i]=t;

	
return j;
		
	}
	if(i>j){

		int t = ar[pos];
		ar[pos]=ar[i];
		ar[i]=t; 

			return j;
			}
			else {
			

				int t=ar[i];
		ar[i]=ar[j];
		ar[j]=t;

				}
	}
	
}
return 0;
}
void Qsort(int first,int last,int val,int ar[])
{

	if(first<last-1)
	{	
		int j=part(first,last,val,ar);			
		if(j!=first)
		Qsort(first,j+1,ar[j],ar);
		if(first!=j)
		Qsort(j+2,last,ar[last-1],ar);
		else {
			Qsort(j+1,last,ar[last-1],ar);
			}			
	}
}
int main()
{
	int ar[5000];
		scanf("%d",&size);
		int j;
		for(j=0;j<size;j++)
		{
			scanf("%d",&ar[j]);
		}
	Qsort(0,size,ar[size-1],ar);
	printf("\n");
for(j=0;j<size;j++)
				printf("%d ",ar[j]);
				printf("\n");

}