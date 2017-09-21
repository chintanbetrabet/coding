#include<stdio.h>
int moves=0;
long long mod(long long base,int exp,long m)
    {
	    
	 moves++;
    //printf("m=%d\n",moves);
	    if(exp==0){
		    //printf("return 1");
	    return 1;
	    }
       else if(exp==1)
            {
            return base%m;
            }
         
   else if(exp%2==0&&exp!=0){
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
	long long unsigned n=10000000;
	
	int k=5;
	scanf("%lld %d",&n,&k);
	long long unsigned i;
	long long unsigned sum=0;
	long unsigned const m=100000007;
	int ar[m]={};
	
	if(k==0)
	sum=n;
	else{
	for(i=1;i<=n;i++)
	{
	long long add=mod(i,k,m);
	sum+=add;
	ar[add]++;
	if(ar[add]>1)
	{
		printf("dup");break;
	}
	sum%=m;
		//printf("i=%d  ",i);
		//printf("v=%llu \n",add);
	}
	}
//	sum%=m;

sum%=m;
printf("%lld",sum);
}