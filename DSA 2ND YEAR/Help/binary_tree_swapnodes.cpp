#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void inorder(int i,int nodes[1024][2])
{
	if(i>0)
	{
		inorder(nodes[i][0],nodes);
		cout<<i<<" ";
		inorder(nodes[i][1],nodes);
		
	}
	
}
void swapdfs(int i,int nodes[][2],int h,int k)
{
	if(i>0){
	//cout<<"\ni="<<i<<" l="<<nodes[i][0]<<" r="<<nodes[i][1]<<" h="<<h<<" p="<<pi;
	if(h%k==0)
	{
		int t=nodes[i][0];
		nodes[i][0]=nodes[i][1];
		nodes[i][1]=t;
	}
	//if(2*i+1<size)
	swapdfs(nodes[i][0],nodes,h+1,k);
	//else cout<<"\nLEFT OB for i="<<i;
//	if(2*i+2<size)
	swapdfs(nodes[i][1],nodes,h+1,k);
	//else cout<<"\nright OB for i="<<i;
}
}
void dfs(int pi,int i,int nodes[][2],int h,int k,int size)
{

if(i>0){
	cout<<"\ni="<<i<<" l="<<nodes[i][0]<<" r="<<nodes[i][1]<<" h="<<h<<" p="<<pi;
	
	//if(2*i+1<size)
	dfs(i,nodes[i][0],nodes,h+1,k,size);
	//else cout<<"\nLEFT OB for i="<<i;
//	if(2*i+2<size)
	dfs(i,nodes[i][1],nodes,h+1,k,size);
	//else cout<<"\nright OB for i="<<i;
}		
	

}

int main() {
    int n,k=1;
    cin>>n;
    int nodes[1024][2];
 
		
    for(int i=1;i<=n;i++)
    {
		 cin>>nodes[i][0]>>nodes[i][1];
	 }
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>k;
		swapdfs(1,nodes,1,k);
   	inorder(1,nodes);
   	
   cout<<"\n";
	}

   

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}