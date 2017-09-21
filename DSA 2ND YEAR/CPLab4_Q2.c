#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
if(n%10==0)
	{
		printf("Divisible by 2");
		n/=10;
		if(n%10==0)
		{
			printf(",4");
			n/=10;
		if(n%10==0)
		{
			printf(",8");
		}
		}
	}
else printf("Not Divisible");
}