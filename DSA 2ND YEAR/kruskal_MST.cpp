#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int sets[112345];
int size[112345];
void initialize_set()
{
	for(int i=0;i<112345;i++)
	{
		sets[i]=i;
		size[i]=1;
	}
}
bool compare(pair< int , pair< int,int > > e1,pair< int , pair< int,int > > e2)
    {
    if(e1.first < e2.first)
        {
        return true;
    }
    else if(e1.first > e2.first)
        {
        return false;
    }
    else {
        if(e1.second.first+e1.second.second < e2.second.first+e2.second.second)
            {
            return true;            
        }
        else return false;
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
bool union_set(int a,int b,int n)
{
	if(size[a]>size[b])
	{
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
        if(size[findroot(a)]<n-1)
            return true;
        return false;
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
		sets[findroot(a)]=findroot(b);
        if(size[findroot(b)]<n-1)
            return true;
        return false;
	}
	
}
bool find(int a,int b)
{
	return findroot(a)==findroot(b);
}
void Kruskal(vector< pair< int , pair< int,int > > > edges,int n,int pr)
    {
    initialize_set();
    unsigned int ind=0;
    int w=0;
    
    while(ind <edges.size())
        {
        int v1=edges[ind].second.first;
        int v2=edges[ind].second.second;
        int wt=edges[ind].first;
        ind++;
        if (!find(v1,v2))
            {
            w+=wt;
            union_set(v1,v2,n);
        }
    }
  cout<<w*pr<<endl;
    
}
int main() {
    int m,t,n,pr;
    cin>>t>>pr;
    for(int te=0;te<t;te++){
    cin>>n>>m;
    vector< pair< int , pair< int,int > > > edges;
    for(int i=0;i<m;i++)
        {
        int p,c,w;
        cin>>p>>c>>w;
        pair <int,int> p1;
        p1.first=p;
        p1.second=c;
        pair<int, pair<int,int> > ed;
        ed.first=w;
        ed.second=p1;
        edges.push_back(ed);
      }
    sort(edges.begin(),edges.end(),compare);
    Kruskal(edges,n,pr);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
