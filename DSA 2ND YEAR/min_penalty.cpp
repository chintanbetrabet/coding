#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

int mined[5000]={};
	set< pair<int,int> >ps;

class Node{
	int color;
	int childcolor;
	int dist;
	vector<int> adj;
    vector<int>ws;
public:
	Node()
	{
		color=-1;
		childcolor=-1;
		dist=-1;
	}
	void push(int v,int w){
		adj.push_back(v);
        ws.push_back(w);
		}
	int setD(int d)
	{
		if(dist==-1||dist>=d)
		{
			dist=d;
			return 1;
		}
	
		return 0;
	}
	int getD()
	{
		return dist;
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
    int getW(int i)
        {
        return ws[i];
    }
	void setC(int col)
	{
		color=col;
	}
};

int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}
int dist[3001]={};
int visited[3001]={};
void dfs(Node nodes[],int a,int b,int w)
    {
    if(dist[a]<=w)
        return ;        
        
        dist[a]=w;
        for(int i=0;i<nodes[a].getSize();i++)
            {
            dfs(nodes,nodes[a].getNeighbour(i),b,w|nodes[a].getW(i));
        }
    

}
int main(){
int n,e,t;
	 t=1;
	 for(int c=0;c<t;c++){
		 
	 cin>>n>>e;
	 Node nodes[3001];	
	 for(int i=0;i<e;i++)
	 {	
		 int p,c,w;
		 cin>>p>>c>>w;
		//cout<<"\nP:"<<p<<"C:"<<c;
	 nodes[p].push(c,w);
	 nodes[c].push(p,w);
	 }
     int a,b;
         cin>>a>>b;
     for(int c1=0;c1<3001;c1++)
         {
         dist[c1]=1000000;
     }
         dfs(nodes,a,b,0);
         if(dist[b]!=1000000)
         cout<<dist[b];
         else cout<<"-1";
}
}
