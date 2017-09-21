#include<stdio.h>
int moves=0;
long long mod(long long base,int exp,long m)
    {
	 moves++;
    //printf("m=%d\n",moves);
	    if(exp==0)
	    return 1;
        if(exp==1)
            {
            return base%m;
            }
         
    if(exp%2==0){
	    long long v=mod(base,exp/2,m);
    return (v*v)%m;
    }
    else {
	    long long v=mod(base,exp/2,m);
          return (v*v*base)%m;
        }
    }
int main()
{
	long long unsigned n=1000000;
	int k=1000000;
//	scanf("%lld %d",&n,&k);
	long long unsigned i=n;
	long long unsigned sum=0;
	long m=1000000007;


	
	for(i=1;i<=n;i++)
{
	//	printf("%lld",sum);
		sum+=mod(i,k,m);
		if(sum>m)
		sum%=m;
		//printf("%d\n",i);
	}
//	sum%=m;

printf("%llu",sum);
                               
}