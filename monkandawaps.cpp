#include<bits/stdc++.h>
using namespace std;
using namespace std;
 
// Function returns the minimum number of swaps
// required to sort the array
void swap(int &a,int &b)
{
int t=a;
a=b;
b=t;
}
int level(int i)
{
int l=1;
while(i>0)
	{
	i/=2;
	l+=1;
	}
return l;

}

int binary_search(int e,int ar[],int size)
{
int hi=size-1;
int lo=0;
while(hi>lo)
	{
	int mid=(hi+lo)/2;
		if(ar[mid]==e)
			{
			return mid;
			}
	else if(ar[mid] >e) hi=mid-1;
	else lo=mid+1;
	}
return (hi+lo)/2;

}

int binary_search2(int e,int ar[],int size)
{
int hi=size-1;
int lo=0;
while(hi>lo)
	{
	int mid=(hi+lo)/2;
		if(ar[mid]==e)
			{
			return mid;
			}
	else if(ar[mid] >e) hi=mid-1;
	else lo=mid+1;
	}
return (hi+lo)/2;

}


int myminswap(int ar[],int size)
    {
     
    int sorted[size];
    for(int i=0;i<size;i++)sorted[i]=ar[i];
     
    sort(sorted,sorted+size);
    int mods=0;
    int inplace=0;
    int i=size-1;
    int nomod=0;
    int cost=0;
    int runs=0;
    while(nomod<size)
    	{
    	runs++;
    	//cout<<inplace<<endl;
    	if(ar[i]!=sorted[i])
    		{
    			int v=binary_search(ar[i],sorted,size);
    			swap(ar[i],ar[v]);	
    			mods++;	
    			nomod=0;
    			//cout<<" swapped between level "<<level(i)<<" to "<<level(v)<<endl;
			cost+=max(level(i)-level(v),level(v)-level(i));
    		}
    	else
    		{
    		nomod++;
    		}
    	i-=1;
    	if(i==-1)i=size-1;
    	}
    cout<<runs<<endl;
    //cout<<"cost ="<<cost<<endl;
    return mods;
    }

int myminswap2(int ar[],int size)
    {
     
    int sorted[size];
    for(int i=0;i<size;i++)sorted[i]=ar[i];
     
    sort(sorted,sorted+size);
    int mods=0;
    int inplace=0;
    int i=0;
    int nomod=0;
    int cost=0;
    while(nomod<size)
    	{
    	//cout<<inplace<<endl;
    	if(ar[i]!=sorted[i])
    		{
    			int v=binary_search(ar[i],sorted,size);
    			//cout<<"ideally, "<<ar[i]<<" should be at "<<v<<endl;
    			swap(ar[i],ar[v]);	
    			mods++;	
    			nomod=0;
    			//cout<<" swapped between level "<<level(i)<<" to "<<level(v)<<endl;
			cost+=max(level(i)-level(v),level(v)-level(i));
    			//for(int j=0;j<size;j++)
    			//cout<<ar[j]<<" ";
    			//cout<<endl;
    		}
    	else
    		{
    		nomod++;
    		}
    	i+=1;
    	if(i==size)i=0;
    	}
 //   cout<<"cost ="<<cost<<endl;
    return mods;
    }

int pos=0;
int ino[112345];
void inorder(int ar[],int ind,int n)
{
if(ind>=n)return;
inorder(ar,ind*2+1,n);
ino[pos++]=ar[ind];
inorder(ar,2*ind+2,n);
}
int main()
{
int t;
cin>>t;
while (t--)
{
 int n;
 cin>>n;
 int ar[n];
 for(int i=0;i<112345;i++)ino[i]=0;
 int i=0;
 int k=n;
 while(n--)
 {
 cin>>ar[i++];
 }
}
 //inorder(ar,0,k);
//cout<<myminswap2(ino,k);
// inorder(ar,0,k);
 cout<<myminswap(ar,k);
}
