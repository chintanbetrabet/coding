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
void shortestPath(Node nodes[])
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
   nodes[val].setD(temph);
   mined[val]=1;
	
	
	for(int i=0;i<nodes[val].getSize();i++)
	{
		int h,pos;
		
	pos=nodes[val].getNeighbour(i);

	if(mined[pos]==0){
        int w=nodes[val].getW(i);
	
			h=w+nodes[val].getD();
			nodes[pos].setD(h);
			pair<int,int> p;
			p.first=h;p.second=pos;
			ps.insert(p);
		
			
			}
			
	

	}	
	shortestPath(nodes);
}
int main()
{
	int n,e,t;
	 cin>>t;
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
	 int r;
	 cin>>r;
	nodes[r].setD(0);
	pair<int,int> pr;
	pr.first=0;
	pr.second=r;

ps.insert(pr);

 pair<int,int> tempo;
	tempo=*ps.begin();

 shortestPath(nodes);
 ps.clear();

 for(int k=1;k<=n;k++)
 mined[k]=0;
 for(int k=1;k<=n;k++)
    {
	    if(k!=r)
	    {
		    cout<<nodes[k].getD()<<" ";
		 }
	 }
         cout<<"\n";         
}

                                                                                      
}

