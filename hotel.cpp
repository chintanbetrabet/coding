#include<bits/stdc++.h>
using namespace std;
bool fun(vector<int> &arrive, vector<int> &depart, int K) {
    priority_queue<int> pq;
    int occ=0;
    vector<pair<int,int> > details;
    
    for(int i=0;i<arrive.size();i++)
    {
        details.push_back(pair<int,int>(arrive[i],depart[i]));
    }
    sort(details.begin(),details.end());
    //pq.push(-1*details[0].second);
    for(int i=0;i<details.size();i++)
    {
    	pq.push(-1*details[i].second);
        occ++;
        //cout<<" starting at i="<<i<<" top is "<<-1*pq.top()<<"  "<<details[i].first<<endl;
        if(!pq.empty() && pq.top()*-1<=details[i].first)
        {
        	//cout<<"at i="<<i<<" pop : "<<-1*pq.top()<<endl;
            pq.pop();
            occ--;
            //pq.push(-1*details[i].second);
            
            while(!pq.empty() && pq.top()*-1<=details[i].first)
            {
            	//cout<<"at i="<<i<<" pop : "<<-1*pq.top()<<endl;
                pq.pop();
                occ--;
            }
            
        }
        
        //cout<<" at end of i="<<i<<" occ="<<occ<<endl;
        if(occ>K)return false;
        
    }
   // cout<<"Occ cc is "<<occ<<endl;
    return true;
}
int main()
{
vector<int> a;
vector<int>b;
int k;
int a1,a2;
cin>>a1;
for(int i=0;i<a1;i++)
	{
	
	int v;
	cin>>v;
	a.push_back(v);
	}
cin>>a2;
for(int i=0;i<a2;i++)
	{
	
	int v;
	cin>>v;
	b.push_back(v);
	}

cin>>k;
cout<<fun(a,b,k);
}
