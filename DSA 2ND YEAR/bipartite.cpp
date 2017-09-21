#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node{
	int color;
	int childcolor;
	vector<int> adj;
public:
	Node()
	{
		color=-1;
		childcolor=-1;
	}
	void push(int v){
		adj.push_back(v);
		}
	int getC()
	{
		return color;
	}
	int getCC()
	{
		return childcolor;
	}
	int getSize()
	{
		return adj.size();
	}
	int getNeighbour(int i)
	{
		return adj[i];
	}
	void setC(int col)
	{
		color=col;
	}
};
int bp=1;
int bipart(int val,Node nodes[])
{
	for(int i=0;i<nodes[val].getSize();i++)
	{
		if(nodes[nodes[val].getNeighbour(i)].getC()==-1)
		{
				if(nodes[val].getC()==1)
						{
							nodes[nodes[val].getNeighbour(i)].setC(2);
						}
				else {
					nodes[nodes[val].getNeighbour(i)].setC(1);
					}
		}
		else if(nodes[val].getC()==nodes[nodes[val].getNeighbour(i)].getC())
		{
			return -1;			
		}
	}
	return 1;
}
void shortestPath(int val,Node nodes[],int weights[][100000])
{
	
}
int main()
{
	 int n,e;
	 cin>>n>>e;
	 Node nodes[n+1];	
	 //int weights[n][n];
	 for(int i=0;i<e;i++)
	 {
		 int p,c;
		 cin>>p>>c;
		// cout<<"\nP:"<<p<<"C:"<<c;
	 nodes[p].push(c);
	 nodes[c].push(p);
	 }
	 int bp=1;
	 nodes[1].setC(1);
	for(int i=1;i<=n;i++)
	 {
		//cout<<"\ni="<<i;
		/* if(bipart(i,nodes)==-1)
		 {
			 bp=-1;
			 break;
		 }*/
		 
	 }	
	 /*for(int i=1;i<=n;i++)
	 {
		 cout<<"\nColor of "<<i<<" = "<<nodes[i].getC();
	 }*/
	 if(bp==-1)
	 cout<<"Not bipartite";
	 else cout<<"bipartite";
	 
}