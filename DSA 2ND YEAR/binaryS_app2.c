#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n,flag=0;
int binary(int up,int lower,int ar[],int v,int s)
    {
    int mid=(up+lower)/2;
      printf("\nUPPer =%d lower=%d mid=%d",up,lower,mid);
     if(ar[up]<v){
	    flag=-1;
     return -1; 
     }
     if(ar[lower]>v)
     {
	      flag=-2;
     return -2; 
	  }
    if(lower>=0&&up>=0&&up<s&&lower<s&&up-lower>1){
    if(up==lower){
    if(ar[mid]==v)return mid;
    else if(v>ar[mid]&&v<ar[mid+1]&&mid<s-1){
	   // printf("U");
	    if(mid==0)flag=1;
	    return -1*mid;
    }
    }

  //  if(up-lower>0){
    if(ar[mid]>v){
	    //printf("U");
        return binary(mid,lower,ar,v,s);
        
        }
    else if(ar[mid]<v){
	   // printf("L");
        return binary(up,mid,ar,v,s);
        
        }
    else if(ar[mid]==v)return mid;
    else return -1*mid;
    }
    else if(up-lower==1)
    {
	    if(ar[up]==v)return up;
	    if(ar[lower]==v)return lower;
	    else 
	    {flag=1;
	    return -1*lower;
	    }
	 }
    
    //}
   //else if(up==lower)
       // {
       // if(ar[up]==v)return up;
       //else return -1*up;
  //  }
  /*
    else{
        printf("br");
        return mid;
    }*/
    return -1;
}
int min(int x,int y)
{
	if(x<y)return x;
	return y;
}
int main() {
    int q,i,ar[100000];
    //int b[]={1,2,3,4,5,6};
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
        {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<q;i++)
        {
        int vi,d;
        float vl;
        scanf("%d %f",&vi,&vl);
        flag=0;
       int pos= binary(n-1,0,ar,vi,n);
      // printf("\ntest %d %d",pos,flag);
        if(pos>=0&&flag==0)
        {
	        d=0;
	     }
	     else {
		    
		     if(flag==1){
		    printf("\nbetween:%d and %d ",ar[-1*pos],ar[-1*pos+1]);
		     d=min(vi-ar[-1*pos],ar[-1*pos+1]-vi);
		     if(vi-ar[-1*pos]>ar[-1*pos+1]-vi)pos=-1*pos+1;
		     
		     }
		     if(flag<0)
		     {
			     if(flag==-2){pos=0;d=(ar[0]-vi);}
			     else if(flag==-1){pos=n-1;d=vi-ar[n-1];}
			     //printf("Does not exist");
			  }
		     
		     }
		     if(vl>=d*2)
		     printf("\n%d:%d\n",vi,ar[abs(pos)]);
		     else printf("-1\n");
		     //printf("POS=%d D=%d vi=%d\n",pos,d,vi);
	     
      }
    
      return 0;
}
