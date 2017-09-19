
#include<bits/stdc++.h>
using namespace std;
int mined[1123456]={};
int mindis[1123456];
priority_queue<pair<int,int> > pq;
void djistra(vector<pair<int,int> > g[])
    {
        pq.push(pair<int,int>(0,0));
        while(!pq.empty())
        {
         pair<int,int> node=pq.top();
         pq.pop();
         int num=node.first;
         int dis=node.second;
         mined[num]=1;
         mindis[num]=min(dis,mindis[num]);
         for(int i=0;i<g[num].size();i++)
         	{
         	int temp=g[num][i].first;
         	if(mined[temp]==0)
         		{
         		pq.push(g[num][i]);
         		}
         	}
        }
    }
   int main()
   {
   }
   //return max(max(djisktra(g,0,nums.size()+2),djisktra(g,0,nums.size()+1)),max(djisktra(g,1,nums.size()+2),djisktra(g,1,nums.size()+1)));
