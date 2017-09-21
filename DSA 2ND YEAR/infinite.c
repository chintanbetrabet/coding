#include<stdio.h>
int bins(int max,int min,int n)
{
	//printf("%d %d\n",max,min);
	int mid=min+(max-min)/2;
	//if(n<3)return 1;
	if(max-min>1){
	//	printf("\nYO");
	if(mid*(mid+1)<2*n)
	{//printf("\n UP");
		return bins(max,mid,n);
	}
	else if(mid*(mid+1)>2*n)
	{
		//printf("\n Down");
		return bins(mid,min,n);
	}
	else {//printf("for n:%d MID",n);
	return mid-1;}
	}
	if(max-min<=1){
//	printf("\nM=%d m=%d ",max,min);
	
   
	return min;
	

	}
	//else return min;
}
int main()
{int n;
	scanf("%d",&n);
	int k=bins(100,0,n);
	int v=n-((k*(k+1))/2);
	printf("%d",v);
	}
}