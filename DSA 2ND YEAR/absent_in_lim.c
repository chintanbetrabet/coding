#include<stdio.h>
int main()
{
	int n,i,q;
	int ar[100005];
	long long int sum[100005]={};
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);sum[i]=sum[i-1]+ar[i];		
	}
		for(i=1;i<=n;i++)
	{
		//printf("i:%d=%llu \n",i,sum[i]);		
	}
	
//	printf("YES1\n");
	for(i=0;i<q;i++)
	{
		int u,l,v;int index=-1;
		scanf("%d %d %d",&l,&u,&v);
		int loop;
		int mid_sum=sum[u]-sum[l-1];
		int num_el=u-l+1;
			if(num_el*v==mid_sum)
			{
			printf("MAYBE");
			int var;
				for(var=l;var<=u;var++)
				{
					if(ar[var]!=v){
					index=var;
				//printf("Val=%d",index);
					var=u;break;
					}
					
				}
				//break;
			}
	
		//printf("%d %d:%llu %d",l,u,sum[u],v);
	/*	while(u>l)
		{
			
			
			

			//else {
			//	printf("YES");
			//	while(u>l)	
				//{
						int mid=(u+l)/2;
						//printf("MID=%d ",mid);
						if(ar[mid]!=v)
						{
							index=mid;
							break;
						}
						else if(sum[mid]-sum[l-1]!=(mid-(l-1))*v)
						{
						//printf("UP");
						u=mid;
						}
						else {
							l=mid;//printf("DOWN");
							}
					//}
			
									
			//	}					
									
				}
				if(ar[u]!=v&&index==-1){//printf("PITY");
				index=u;}*/
	printf("%d\n",index);	
		
	}
	//printf("DONE");	
}