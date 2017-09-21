#include <stdio.h>
#include <string.h>
#include <math.h>

double log2(int v)
    {
    return (log(v))/log(2);
}
int main() {/*
int t;
    int h;
    scanf("%d",&t);
    for(h=0;h<t;h++)
        {
        long long unsigned int moves=6,count=0;
   scanf("%llu",&moves);
    
    while(moves>1)
    {
	    //printf("m:%llu",moves); 
   // printf("\n%llu %llu",moves,count);getch();
	    if(pow(2,int(log2(moves)+1))==moves)moves/=2;
	    else {
		    moves-=pow(2,int(log2(moves)));
		    }
	   count=(count+1)%2;
	    
	 }
	 if(count==1)
    printf("Louise\n");
    else printf("Richard\n");
    
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned x=~0; 
    printf("%u",x);
    return 0;
}
