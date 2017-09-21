#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;
set < pair<int,pair<int,int> > > edges;
int visited[30001]={};
int mstVal=0;
void getMstVal()
{
	while(edges.empty()==false)
	{
	pair<int,pair<int,int> >tempo;
	tempo=*edges.begin();
	edges.erase(tempo);
	int p=tempo.second.first;
	int c=tempo.second.second;
	if(!(visited[p]&&visited[c]))
		{
			visited[p]=visited[c]=1;
			mstVal+=tempo.first;
		}
	}
}
int main()
{
	int n,e;
	vector<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.clear();
   cin>>n>>e;
	 	
	 //int weights[3001][3001];
	 for(int i=0;i<e;i++)
	 {	
		 int p,c,w;
		 cin>>p>>c>>w;
		 pair<int,int> ends;
		 ends.first=p;ends.second=c;
		 pair<int,pair<int,int> > store;
		 store.first=w;
		 store.second=ends;
		 edges.insert(store);
	}
	int r;
	cin>>r;
	getMstVal();
	cout<<mstVal;*/
	
}