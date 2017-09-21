#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int sets[112345];
int size[112345];
vector< pair< int , pair< int,int > > > spare;
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
    if(e1.first > e2.first)
        {
        return true;
    }
    else 
        {
        return false;
    }

}
int findroot(int a)
{
	int i=a;
	while(sets[i]!=i||sets[i]==-1)
	{
        if(sets[i]!=-1)
	i=sets[i];
        else {
            i=-1;
            break;
        }
	}
	return i;
}

bool union_set(int a,int b,int n)
{
    if(findroot(a)!=-1&&findroot(b)!=-1){
        cout<<"HI";
	if(size[a]>size[b])
	{
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
        
            return true;
        
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
		sets[findroot(a)]=findroot(b);
        
            return true;
       
	}
    }
  
	return false;
}
bool find(int a,int b)
{
	return findroot(a)==findroot(b);
}
void Kruskal(vector< pair< int , pair< int,int > > > edges,int n)
    {
    
    int ind=0;
    int w=0;
    int cont=true;
    cout<<"SIZE+"<<edges.size();
    while(ind <edges.size())
        {
        cout<<"\nind=:"<<ind;
        int v1=edges[ind].second.first;
        int v2=edges[ind].second.second;
        int wt=edges[ind].first;
        
        if (!find(v1,v2))
            {
            cout<<"HI";
            if(union_set(v1,v2,n))
                w+=wt;
            else {
                cout<<"\nrejected "<<edges[ind].first<<" "<<edges[ind].second.first<<" "<<edges[ind].second.second;
                    }
            cout<<"DONE";
        }
        ind++;
    }
  cout<<w;
    
}
int main() {
    int k,n;
    cin>>n>>k;
    vector< pair< int , pair< int,int > > > edges;
    for(int i=0;i<n-1;i++)
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
    
    initialize_set();
    for(int i=0;i<k;i++)
        {
        int x;
        cin>>x;
        sets[x]=-1;
    }
    sort(edges.begin(),edges.end(),compare);
   
    for(int i=0;i<edges.size();i++)
        {
        cout<<"\n"<<edges[i].first<<" "<<edges[i].second.first<<" "<<edges[i].second.second;
    }
    Kruskal(edges,n);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
