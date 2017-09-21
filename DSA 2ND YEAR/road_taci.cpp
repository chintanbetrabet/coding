#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;
int mined[6002]={};
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
	//cout<<tempo.second<<"\n";
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

int main() {
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
        {
        Node nodes[6002];

        int m,n;
        cin>>n>>m;
        for(int i=0;i<m;i++)
            {
            int x,y,r,t;
            cin>>x>>y>>r>>t;
            nodes[x].push(y,r);
            nodes[y].push(x,r);
            nodes[x+3000].push((y+3000),r);
            nodes[y+3000].push((x+3000),r);
           nodes[x].push((y+3000),t);
           nodes[y].push((x+3000),t);

        }
        int S,D;
        cin>>S>>D;
        nodes[S].setD(0);
	pair<int,int> pr;
	pr.first=0;
	pr.second=S;
ps.insert(pr);
shortestPath(nodes);
/*
if(nodes[D].getD()==-1&&nodes[D+3000].getD()==-1)
    {
    cout<<"NONE\n";
}
        else if(nodes[D].getD()==-1)
            cout<<nodes[D+3000].getD()<<"\n";
        else if(nodes[D+3000].getD()==-1)
            cout<<nodes[D].getD()<<"\n";
else if(nodes[D].getD()>=0&&nodes[D+3000].getD()>=0)
    {
    if(nodes[D].getD()>=nodes[D+3000].getD())
        cout<<nodes[D+3000].getD()<<"\n";
   else cout<<nodes[D].getD()<<"\n";
}*/

cout<<min(nodes[D].getD(),nodes[D+3000].getD())<<"\n";
// cout<<nodes[D].getD();
         for(int k=0;k<=6001;k++)
 mined[k]=0;
        ps.clear();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
