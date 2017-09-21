#include<stdio.h>
int main()
{
	printf("%c",0x61);
/*	int n,i,q;
	int ar[100005];
	long long int sum[100005]={};
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);sum[i]=sum[i-1]+ar[i];		
	}
		for(i=1;i<=n;i++)
	{
		printf("i:%d=%llu \n",i,sum[i]);		
	}
//	printf("YES1\n");
	for(i=0;i<q;i++)
	{
		int u,l,v;
		scanf("%d %d %d",&l,&u,&v);
		printf("%d %d:%llu %d",l,u,sum[u],v);
		if(sum[u]-sum[l-1]!=(u-l+1)*v)
		printf("NO from %llu %llu\n",sum[l-1],sum[u]);
		else printf("MAYBE from l=%d=%llu u=%d=%llu v=%d",l,sum[l-1],u,sum[u],v);
	}
	//printf("DONE");	*/
}