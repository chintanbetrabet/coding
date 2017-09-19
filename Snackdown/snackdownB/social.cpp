#include<bits/stdc++.h>
using namespace std;
#define L(i,n) for(int i=0;i<n;i++)

int nextGen[501][501];
int ar[501][501];

int bestgrid(int nextD,int i,int j,int m,int n)
{


				if(i>0)//up
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i-1,j,m,n),nextGen[i][j]);
				}
				if(j>0)//left
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i,j-1,m,n),nextGen[i][j]);
				}
				if(i<n-1)//down
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i+1,j,m,n),nextGen[i][j]);
				}
				if(j<m-1)//right
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i,j+1,m,n),nextGen[i][j]);
				}
				if(j<m-1 && i<n-1) //right down
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i+1,j+1,m,n),nextGen[i][j]);
				}
				if(j<m-1 && i>0) //right up
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i-1,j+1,m,n),nextGen[i][j]);
				}
				if(j>0 && i<n-1) //left down
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i+1,j-1,m,n),nextGen[i][j]);
				}
				if(j>0 && i>0) //left up
				{
				nextGen[i][j]=max(1+bestgrid(maxv,i-1,j-1,m,n),nextGen[i][j]);
				}
	
	
return nextGen[i][j];
}

int main()
{
int t;
cin>>t;
while(t--)
	{
	int m,n;
	cin>>n>>m;
	int starti,startj;
	int maxv=0;
	
		L(i,n)
		{
		L(j,m)
			{
			cin>>ar[i][j];
			if(ar[i][j]>maxv)
				{
				starti=i;
				startj=j;
				}
			maxv=max(maxv,ar[i][j]);
						
			}
		}
	
	L(i,n)L(j,m)
		{
		nextGen[i][j]=ar[i][j]==maxv?0:-1;
		}
	L(i,n)
		{
		L(j,m)
			{
			bestgrid(maxv,starti,startj,m,n);			
			}
		}
	L(i,n)
	{
	cout<<endl;
	L(j,m)cout<<nextGen[i][j]<<" ";
	}
	cout<<endl<<endl;
	}
	
}
