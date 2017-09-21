#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

int mined[5000]={};
	set< pair<int,int> >ps;
// Usage

//pair<int,int>p;
//ps.insert(p);
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
	//	cout<<" \nEmpy\n";
		return;
	}                                       
	pair<int,int> tempo;
	tempo=*ps.begin();
	//cout<<tempo.first;
  //  cout<<"\nSTILL HAS:  "<<ps.size()<<" ELEMNETS: "<<tempo.second<<","<<tempo.first<<"\n";
	ps.erase(ps.begin());
   int val=tempo.second;
	int temph=tempo.first;
   //cout<<"\nread:"<<val<<","<<temph;
   nodes[val].setD(temph);
   mined[val]=1;
	//x.pop();
	
	for(int i=0;i<nodes[val].getSize();i++)
	{
		int h,pos;
		
	pos=nodes[val].getNeighbour(i);
//	cout<<"\npos="<<pos<<" val ="<<mined[pos]<<"\n";
	if(mined[pos]==0){
        int w=nodes[val].getW(i);
	//cout<<val<<"->"<<pos<<"\n";
	//	if(nodes[pos].getD()==-1)
	//	{
			h=w+nodes[val].getD();
			nodes[pos].setD(h);
			pair<int,int> p;
			p.first=h;p.second=pos;
			ps.insert(p);
		//	cout<<"\n add:"<<p.first<<","<<p.second;
			
			}
			//cout<<"\nNew node "<<pos;	
			
		//}
	//	else {
			//int oldh=nodes[pos].getD();
	//	h=nodes[val].getD()+w;
		
	//	cout<<"\n Try SET H="<<h<<" for node "<<pos;
	                                            
     
		//shortestPath(nodes);
	
		
	//	}
	

	}	//else cout<<"\nreject"<<val<<"  at"<<temph;*/
	shortestPath(nodes);
}
int main()
{
	int n,e,t;
	 cin>>t;
	 for(int c=0;c<t;c++){
		 
	 cin>>n>>e;
	 Node nodes[3001];	
	 //int weights[3001][3001];
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


	/*pr.first=3;
	pr.second=1;
	x.push(pr);
	cout<<"\n"<<x.top().first;*/

 pair<int,int> tempo;
	tempo=*ps.begin();
 //cout<<"\nSTILL HAS:  "<<ps.size()<<" ELEMNETS: "<<tempo.second<<","<<tempo.first<<"\n";
 /*for(int i8=0;i8<nodes[1].getSize();i8++)
 {
	 cout<<nodes[1].getNeighbour(i8)<<"\n";
 }*/
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
//int bp=1;
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