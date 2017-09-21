#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nodes[100001];
vector<int> tree[100001];

vector< int > anc1[100001];
void ins(int val,int p)
    {
    anc1[val]=anc1[p];
    //nodes[val].anc=nodes[p].anc;
	int h=nodes[p];
	/*pair<int,int>temp;
	temp.first=h;
	temp.second=p;*/
	h++;
	nodes[val]=h;	
	anc1[val].push_back(p);
}
int bins(int x,int k)
    {
    if(k>nodes[x])
        return 0;
    return anc1[x][nodes[x]-k+1];
}
void dfs(int val,int p)
{   //cout<<"VAL:"<<val;
	ins(val,p);
	for(unsigned int i=0;i<tree[val].size();i++)
	dfs(tree[val][i],val);
}
int main() {
    int t;
    cin>>t;
  
    for(int tests=0;tests<t;tests++)
        {
	        
        int v,r;
        cin>>v;
        int alive[100001]={};
        for(int i=1;i<=v;i++)
            {
            int p,c;
            cin>>c>>p;
            if(p==0)
                r=c;
            else{
                tree[p].push_back(c);
               }
            alive[p]=alive[c]=1;
        }
        nodes[0]=-1;
        dfs(r,0);
        /*for(int a=0;a<100000;a++)
        {
	        if(nodes[a].anc.size())
                {
	                cout<<a<<" : ";
	                for(int b=0;b<nodes[a].anc.size();b++)
	                {
		                cout<<"("<<(nodes[a]-nodes[a].anc[b].first)<<"th,"<<nodes[a].anc[b].second<<" ) ";
		            }
                cout<<"\n";
            }
            
	    }*/
        
        int qs;
        cin>>qs;
        for(int qi=0;qi<qs;qi++)
            {
            int type;
            cin>>type;
            switch(type)
                {
                case 0:{
                    
                    int p,c;
                    cin>>p>>c;
                    if(alive[c]==0){
                    ins(c,p);  
                        alive[c]=1;
                    }
                   }break;
                case 1:
                {
                    int c;
                    cin>>c;
                    alive[c]=0;
                    anc1[c].clear();
                }break;
                case 2:{
                    int x,k;
                    cin>>x>>k;
                    if(alive[x]){
                    cout<<bins(x,k)<<"\n" ;     
                    }
                    else{
                        cout<<"0"<<"\n" ;
                    }
                }break;
            }
        }
        for(int cl=0;cl<100001;cl++)
        {
            tree[cl].clear();
            anc1[cl].clear();
            nodes[cl]=0;
        }
        
    }
    
    return 0;
}
