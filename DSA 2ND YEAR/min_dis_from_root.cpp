#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node{
private:
	int height;
	int val;
	int top;
	vector<int> neighbours;
public:
	Node()
	{
		height=-1;
		val=-1;
		top=0;
	}
	Node (int val)
	{
	   height=-1;
		val=-1;
		top=0;
	}
	int getHeight()
	{
		return height;
	}
	void setHeight(int h)
	{
		height=h;
	}
	int getVal()
	{
		return val;
	}
	void setVal(int v)
	{
		val=v;	
	}
	void push(int val)
	{
		neighbours.push_back(val);
	}
	int pop()
	{
		return neighbours[top++];
	}
	int getSize()
	{
		return neighbours.size();
	}
	int getNeighbour(int i)
	{
		return neighbours[i];
	}
	
};

unsigned int qtop=0;	vector<int> queue;
void bfs(int ph,int val,vector<Node>nodes)
{
	
} 
int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}

void queueUp(int val,Node nodes[],int queued[])
{
//cout<<" \nCALL on "<<val<<"\n ";
	int i;
	int h=nodes[val].getHeight();
	for(i=0;i<nodes[val].getSize();i++)
	{
		int pos=nodes[val].getNeighbour(i);
		if(nodes[pos].getHeight()==-1)
		{
			nodes[pos].setHeight(h+1);
		}
		else {
			int h1=min(h+1,nodes[pos].getHeight());
			nodes[pos].setHeight(h1);
			}
		
	//	cout<<"\ndone node:"<<val<<"-> "<<nodes[val].getNeighbour(i);
		if(!queued[pos]){
		//	cout<<" doing";
		queue.push_back(pos);
		queued[pos]=1;
		}
	//	else cout<<"\nvisited "<<nodes[val].getNeighbour(i);
	}
	/*cout<<"\nQUEUE : top="<<qtop<<"\n";
		for(unsigned int k=0;k<queue.size();k++)
		{
			cout<<queue[k]<<"  ";
		}
		cout<<endl;
		cout<<"\nVisited:";
			for(unsigned int k=0;k<6;k++)
		{
			cout<<queued[k]<<"  ";
		}*/
	if(qtop<queue.size()-1)
	{	
		qtop++;
	//	cout<<"QT="<<qtop<<" S+"<<queue.size();
		
		queueUp(queue[qtop],nodes,queued);
	}
}
int main()
{
	int t,n,i,e;
	cin>>t;
	for(i=0;i<t;i++){
	cin>>n>>e;
//	cout<<"n="<<n<<" "<<e;
	Node nodes[1000];
	for(int j=0;j<e;j++)
		{
			int n1,n2;
			cin>>n1>>n2;
			nodes[n1].push(n2);
			nodes[n2].push(n1);
		//cout<<"HI "<<j<<"  "<<e;			
		}
//	cout<<"done";
		int r;
		int queued[1000]={};
	

		cin>>r;
		queue.push_back(r);
		queued[r]=1;
		nodes[r].setHeight(0);
		queueUp(r,nodes,queued);
	//	cout<<"done again\n";
		for(unsigned int k=1;k<=n;k++)
		{
			if(nodes[k].getHeight()>0)
			cout<<nodes[k].getHeight()*6<<" ";
			else if(nodes[k].getHeight()<0)cout<<"-1 ";
		}
		cout<<"\n";
		queue.resize(0);
		qtop=0;
		
	}
}