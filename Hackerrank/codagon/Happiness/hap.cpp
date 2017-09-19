#include <bits/stdc++.h>

using namespace std;
#define VERT 512345
#define cmp components
#define mp make_pair
int sets[VERT];
int size[VERT];
void initialize_set();
int findroot(int a);
void union_set(int a,int b);
bool find(int a,int b);

vector<int> g[VERT];
int visited[VERT];
int comp=0;
int useless=0;
int ones=0;


void dfs(int ind)
{
comp+=1;
visited[ind]=1;
if(g[ind].size()==1)ones++;
for(int i=0;i<g[ind].size();i++)
	{
	if(visited[g[ind][i]]){
	continue;
	}
	dfs(g[ind][i]);
	}
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    initialize_set();
    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        cin >> x >> y;
        if(find(x,y))
        {
        useless++;
        }
        else{
union_set(x,y);
        g[x].push_back(y);
        g[y].push_back(x);
        }
    }
    long long maxsc=0;
    vector<pair<int,int> > cmp;
    for(int i=1;i<=n;i++)
    {
    if(!visited[i])
    	{
    	comp=0;
    	ones=0;
    	dfs(i);
    	cmp.push_back(mp(comp,ones));
    	//cout<<" component of "<<i<<" "<<comp<<" "<<ones<<endl;	
    	maxsc+=(comp-1)*(comp);
    	}
    }
    //cout<<" useless ="<<useless<<" maxsc "<<maxsc<<endl;

    sort(cmp.begin(),cmp.end());
    int need=2-useless;
    int c=0;
    while(need>0 && c<cmp.size())
    	{
    	//cout<<"checking :"<<cmp[c].first<<","<<cmp[c].second<<endl;
    	int myones=cmp[c].second;
    	if(myones>1&&need>1)
    		{
    		maxsc-=cmp[c].first*(cmp[c].first-1);
    		maxsc+=(cmp[c].first-1)*(cmp[c].first-2);
    		
    		maxsc-=(cmp[c].first-1)*(cmp[c].first-2);
    		maxsc+=(cmp[c].first-2)*(cmp[c].first-3);
    		
    		need-=2;
    		}
    	else if(myones>=1)
    		{
    		maxsc-=cmp[c].first*(cmp[c].first-1);
    		maxsc+=(cmp[c].first-1)*(cmp[c].first-2);
    		need-=1;
		}
		c++;
    	}
    cout<<maxsc;
    
    return 0;
}

void initialize_set()
{
	for(int i=0;i<VERT;i++)
	{
		sets[i]=i;
		size[i]=1;
	}
}
int findroot(int a)
{
	int i=a;
	while(sets[i]!=i)
	{
	i=sets[i];
	}
	return i;
}
void union_set(int a,int b)
{
	if(size[a]>size[b])
	{
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
		sets[findroot(a)]=findroot(b);
	}	
}
bool find(int a,int b)
{
	return findroot(a)==findroot(b);
}
