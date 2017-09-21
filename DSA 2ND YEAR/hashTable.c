#include<stdio.h>
int main()
{
	int ar[1000010]={0};
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int v;
		scanf("%d",&v);
		ar[v]++;
	}
		scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int v;
		scanf("%d",&v);
		ar[v]--;
	}
	for(i=1;i<1000010;i++)
	{
		if(ar[i]!=0)
		printf("%d ",i);
	}
	return 0;
}
