#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int days=0;
//vector<long> ar;
int ar1[100000];
int kill(int sts)
    {
    //int ar[100000];
    int dels=0;
    //int size=sts;
    int ind=1;
    int nsize=1;
    for(int i=1;i<sts;i++)
        {
        if(ar1[i]<=ar1[i-1])
            {
           // cout<<"\n"<<"i="<<i<<" add "<<ar1[i]<<" as it is < "<<ar1[i-1];
            ar1[ind++]=ar1[i];
        }
        else {
        
            dels++;
        }
    }


    if(dels>0)
        {
        days++;
        /////for(int i=0;i<ind;i++)
          //cout<<ar1[i]<<" ";
      // cout<<endl;
        return kill(ind);
    }
    else {
     
        return 0;
    }
    return 0;
    
}

int main() {
	int i,n;
	cin>>n;
	
    int s=0;
	for(i=0;i<n;i++)
	{
        int v;
        cin>>v;
		ar1[s++]=v;
	}
	kill(s);
    cout<<days;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    /*for(int i=0;i<100000;i++)
    cout<<"2 "; */ 
    return 0;
}
