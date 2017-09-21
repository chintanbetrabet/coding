#include<stdio.h>
void cumu_sum(int source[],int dest[],int size)
{
	int i;
	dest[0]=source[0];
	for(i=1;i<size;i++)
	dest[i]=dest[i-1]+source[i];
}
int main()
{
	int ar1[]={-2,0,-1,-99999999,5,-99999},ar2[20],size=sizeof(ar1)/4;
	int min=ar1[0],max=ar1[0],mi=0,Mi=0,lp=-1;
	cumu_sum(ar1,ar2,size);
	int i;
	for(i=1;i<size;i++)
	{
		if(ar2[i]>max){max=ar2[i];Mi=i;}
		if(ar2[i]<min){min=ar2[i];mi=i;}
	}
	printf("Mv=%d Mi=%d mv=%d mi=%d\n\n",max,Mi,min,mi);
	int k;
	if(mi>Mi)
	{int j=0;
		while(j<Mi&&ar2[j]<0)
		j++;
		for(k=j;k<=Mi;k++)printf("%d ",ar1[k]);
	}
	else 
	{
		while(mi<Mi&&ar2[mi]<0)
		mi++;
		for(k=mi;k<=Mi;k++)printf("%d ",ar1[k]);
	}
}