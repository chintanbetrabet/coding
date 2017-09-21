#include<stdio.h>
void sortMerger(int u1,int l1,int u2,int l2,int index)
{
	int b[100000],size=0;
	while(l1<=u1&&l2<=u2)
	{
		if(l1<=l2)
		b[size++]=l1++;
		else
		b[size++]=l2++;
		
	}
	while(l1<=u1)b[size++]=l1++;
	while(l2<=u2)b[size++]=l2++;
	int i;
	for(i=0;i<size;i++)
	printf("%d ",b[i]);
}
int main()
{
	sortMerger(4,1,5,3,6);
	return 0;
}
