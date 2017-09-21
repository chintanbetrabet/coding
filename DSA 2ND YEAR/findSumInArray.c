#include<stdio.h>

int bins(int up,int down,int ar[],int val,int size)
    {
	  int m=(up+down)/2;
	  int maxP=m+1;
	  int minP=m;
    while(maxP>down && minP<up-1)
    {
	    int mid=(maxP+minP)/2;
	    if(ar[mid]+ar[mid+1]<val)
	    	{
		    	if(maxP<up)
		    	maxP++;
		    	else if(minP<up-1)minP++;
		    	else return -1;
		    }
	    else if(ar[mid]+ar[mid+1]>val)
	    {
		    if(minP>down)
		    	minP--;
		    	else if(maxP>down)maxP--;
		    	else return -1;
		 }
		 else {
			 printf("%d %d",maxP,minP);
			 return 0;
			 } 
	 }
	 return -1;
}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	if(bins(7,0,a,8,7);
}