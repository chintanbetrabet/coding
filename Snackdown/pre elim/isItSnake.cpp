    #include<bits/stdc++.h>
    using namespace std;
    #define down(k,n) k+n
    #define right(k,n) k+1
    int hmax=0;
    int visited[112345]={};
    int height[112345]={};
    void dfs(vector<int>g[],int src,int h)
    {
	height[src]=max(height[src],h);
if(h>hmax)
	{
	//cout<<"updated at "<<src<<"  to "<<h <<endl;
	hmax=h;
	}
    	visited[src]=1;
    	for(int i=0;i<g[src].size();i++)
    	{
    	if(visited[g[src][i]]==0)
    		dfs(g,g[src][i],h+1);
    	}
    }
    int main()
    {
    int t ;
    cin>>t;
     
    while(t--)
    {
    int n;
    hmax=0;
    int end=-1;
    vector<int>g[112345];
    cin>>n;
    int ar[2*n];
    int nodes=0;
    int start=100000;
    for(int i=0;i<2*n;i++)
    {
    char ch;
    cin>>ch;
    	if(ch=='.')ar[i]=0;
    	else
    	{
    	ar[i]=1;
    	nodes++;
    	start=min(start,i);
    	end=max(end,i);
    	}
    }
    for(int i=0;i<2*n;i++)
    	{
		if(ar[i]==1)
		{
		if(i<n)
		{
		if(ar[i+n]==1)
		g[i].push_back(i+n); //down
		}
		if(i>=n)
		{
		if(ar[i-n]==1)
		g[i].push_back(i-n); //up
		}
		if(i%n!=n-1)
		{
		if(ar[i+1]==1)
		g[i].push_back(i+1); //right
		}
		if(i%n)
		{
		if(ar[i-1]==1)
		g[i].push_back(i-1); //left
		}
		}
		
    	}
   // cout<<"Start="<<start<<" end="<<end<<endl; 
    for(int i=0;i<2*n;i++)
    {
        
    if(ar[i]==1)
    {	
     for(int j=0;j<1100;j++)
    	{
    	visited[j]=0;
    	}
    dfs(g,i,0);

    }
    if(hmax==nodes-1)
    	{
    	//cout<<"src="<<i<<endl;
    	}
   // hmax=0;
    }
    
    dfs(g,start,0);
    for(int j=0;j<1100;j++)
    	{
    	visited[j]=0;
    	}
    dfs(g,end,0);
    
    for(int j=0;j<g[start].size();j++)
    	{
    	for(int i=0;i<1100;i++)
    	{
    	visited[i]=0;
    	}
    	dfs(g,g[start][j],0);
    	}
    	
    	
    	
    	    for(int j=0;j<g[end].size();j++)
    	{
    	for(int i=0;i<1100;i++)
    	{
    	visited[i]=0;
    	}
    	dfs(g,g[end][j],0);
    	}
    if(nodes-1==hmax)cout<<"yes";
    else cout<<"no";
    cout<<endl;
    }
     
    } 
