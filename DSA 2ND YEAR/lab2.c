#include<stdio.h>
#include<conio.h>
int bins_max(int up,int down,int ar[],int val,int size)
    {
	    int mid=(up+down)/2;
	    printf("\ncall on :%d to %d",up,down);getch();
    if(ar[(up+down)/2]==val)
        {
	        printf(" E");
        
        
        while(mid>0&&ar[mid]==val)mid--;
        return mid;
    }
    else if(up==down)
    {printf(" WE");
        if(ar[up]>val)
            while(up>0&&ar[up]>=val)up--;
        else {
            while(up+1<size&&ar[up+1]<val)up++;
        }
        return up;
    }
    else if(val>ar[(up+down)/2]){printf(" e");
        return bins_max(up,(up+down)/2+1,ar,val,size);
        }
    else{ printf("	h	");return bins_max((up+down)/2-1,down,ar,val,size);}
}
int bins_min(int up,int down,int ar[],int val,int size)
    {
	    //printf("call on :%d to %d",up,down);
    if(ar[(up+down)/2]==val)
        {
        int mid=(up+down)/2;
        
        while(mid<size&&ar[mid]<val)mid++;
        return mid;
    }
    else if(up==down)
    {
        
        if(ar[up]>val)
            while(up>0&&ar[up]>=val)up--;
            else {
             while(up<size&&ar[up]<=val)up++;            
        }
        return up;
    }
    else if(val>ar[(up+down)/2])
        return bins_min(up,(up+down)/2+1,ar,val,size);
    else return bins_min((up+down)/2-1,down,ar,val,size);
}
int main()
{
	int ar[]={1,2,3,4,5,9,10};
	printf("%d",bins_min(7,0,ar,8,7));
}