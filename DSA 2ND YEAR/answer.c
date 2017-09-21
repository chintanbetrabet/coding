#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
	int i;
	if(n<2)return 0;
	if(n==2)return 1;
	else
	{
		for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		{//printf("%d / %d\n",n,i);
			return 0;
		}
		}
		return 1;
	}
}
int main()
{
int m,n,i,t,j;
scanf("%d ",&t);
for(j=0;j<t;j++)
	{
		scanf("%d %d",&m,&n);
		for(i=m;i<=n;i++)
		if(isPrime(i)==1)printf("%d \n",i);
		printf("\n");
	}	
	
}