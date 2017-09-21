#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
int count=0;
int bins(int up,int down,int ar[],int val,int size,int given)
    {
	    
    if(ar[(up+down)/2]==val)
        { 
        int mid=(up+down)/2;
             
        return mid;
    }
    else if(up==down)
        return -1;
    else if(val>ar[(up+down)/2])
        return bins(up,(up+down)/2,ar,val,size,given);
    else return bins((up+down)/2,down,ar,val,size,given);
}
int main() {
int t,i,m,n,ar[100000];
    scanf("%d",&t);
    for(i=0;i<t;i++)
        {
        scanf("%d",&n);
        int j;
        for(j=0;j<n;j++)
            {
            scanf("%d",&ar[j]);
        }
        for(j=0;j<n;j++)
        {	//int b[]={1,1,2};
            int mid=bins(n-1,0,ar,ar[j],n,j);
            int ul=mid,ll=mid,given=j,size=n;;
        if(mid!=given)count++;
        while(ul+1<size&&ar[ul+1]==ar[j]){ul++;if(ul!=given){count++;printf(" at j:%d ul=%d",j,ul);}}
        while(ll>0&&ar[ll-1]==ar[j]){ll--;if(ll!=given){count++;printf(" at j:%d ll=%d",j,ll);}}
            printf("HI j:%d mid=%d",j,mid);getch();
        }
        printf("\n%d\n",count);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
