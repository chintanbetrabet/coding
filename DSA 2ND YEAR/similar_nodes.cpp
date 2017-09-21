#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
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
    vector<int> getNeighbours()
        {
       return neighbours;
    }
	
};
int absVal(int x)
    {
    if(x>0)return x;
    else return -1*x;
}
long long int ans=0;
void dfs(int val,Node nodes[],int t,set<int > anc)
    {
    int i;
    anc.insert(val);
   // vector<int> neigh=nodes[val].getNeighbours();
    for(i=0;i<nodes[val].getSize();i++)
        {
       // cout<<val<<","<<nodes[val].getNeighbour(i)<<" " ;
        int pos=nodes[val].getNeighbour(i);
        int low=min(pos-t,t-pos);
        int high=max(pos-t,t-pos);
        
        for(std::set<int>::iterator it=anc.lower_bound(low); it!=anc.upper_bound(high); ++it)
        {
             
            ans++;
        
    }
        dfs(nodes[val].getNeighbour(i),nodes,t,anc);
    }
        //else cout<<cout<<" NO\n";
        
      //  dfs(nodes[val].getNeighbour(i),nodes,root,t,anc1);
    
}
int main()
    {
   int n,i,t;
    int root[100000]={};
	//cin>>t;
	//for(i=0;i<t;i++){
	cin>>n>>t;
//	cout<<"n="<<n<<" "<<e;
	Node nodes[100000];
	for(int j=0;j<n-1;j++)
		{
			int n1,n2;
			cin>>n1>>n2;
        root[n2]=1;
			nodes[n1].push(n2);
		}
    int r;
    for(i=1;i<=n;i++)
        {
        if(root[i]==0)
        {
            r=i;
        }
    }
    //cout<<"root="<<r;
    set<int >anc;
    //pair<int>p ;
    anc.insert (r);
    //for(i=1;i<=n;i++)
        //{
        //anc.resize(0);
       // anc.push_back(i);
       dfs(r,nodes,t,anc);
   // }
    cout<<ans;
}