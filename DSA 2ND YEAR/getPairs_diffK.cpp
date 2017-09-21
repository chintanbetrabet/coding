#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<conio.h>
using namespace std;
int bins(int up,int down,int ar[],int val)
    {
	    printf("call on :%d to %d",up,down);getch();
	    if(up>down){
    if(ar[(up+down)/2]==val)
        {
        return 1;
    }
    else if(up==down)
        return 0;
    else if(val<ar[(up+down)/2])
        return bins(up,(up+down)/2+1,ar,val);
    else return bins((up+down)/2-1,down,ar,val);
    }
    else return 0;
}
int pairs(vector < int > a,int k) {
   int ans;
   int ar[1000000];
    unsigned int i;
    for(i=0;i<a.size();i++)
       { ar[i]=a[i];
        cout<<"\b";
       }
    cout<<bins(a.size(),0,ar,6);
  // Qsort(0,a.size(),ar[0],ar) ;
     return ans;
}
int main()
{
	int ar[]={1,4,5,8,9};
	cout<<bins(sizeof(ar)/4-1,0,ar,7);
}