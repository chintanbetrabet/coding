#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

//int mined[5000]={};
int dist[402][402];
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

void shortestPath(Node nodes[],int r)
{
	
    if(ps.empty()==true)
	{
	return;
	}                                       
	pair<int,int> tempo;
	tempo=*ps.begin();
	ps.erase(ps.begin());
   int val=tempo.second;
	int temph=tempo.first;
    if(temph<dist[r][val]||dist[r][val]==-1)
   dist[r][val]=temph;
   //mined[val]=1;
	
	
	for(int i=0;i<nodes[val].getSize();i++)
	{
		int h,pos;
		
	pos=nodes[val].getNeighbour(i);
    int w=nodes[val].getW(i);
	h=w+dist[r][val]  ;      
	if(h<dist[r][pos]||dist[r][pos]==-1){
        dist[r][pos]=h;
			pair<int,int> p;			
			p.first=h;p.second=pos;
			ps.insert(p);
		
			
			}
			
	

	}	
	shortestPath(nodes,r);
}
int main()
{
	int n,e,t;
	 t=1;
	 for(int c=0;c<t;c++){
		 
	 cin>>n>>e;
	 Node nodes[402];	
	 for(int i=0;i<e;i++)
	 {	
		 int p,c,w;
		 cin>>p>>c>>w;
		//cout<<"\nP:"<<p<<"C:"<<c;
	 nodes[p].push(c,w);
	 //nodes[c].push(p,w);
	 }
    int r;
         //for(int row=0;row<401;row++)
             
    for (r=0;r<=n;r++){
        ps.clear(); 
            for(int col=0;col<402;col++)
             dist[r][col]=-1; 
	dist[r][r]=0;
	pair<int,int> pr;
	pr.first=0;
	pr.second=r;

ps.insert(pr);

 pair<int,int> tempo;
	tempo=*ps.begin();

 shortestPath(nodes,r);
       
}
         int q;
         cin>>q;
         for(int qs=0;qs<q;qs++)
             {
             int p1,p2;
             cin>>p1>>p2;
             cout<<dist[p1][p2]<<endl;
         }
      

     }                                                                                     
}

