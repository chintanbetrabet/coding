#include<bits/stdc++.h>

using namespace std;

int main()
{
int t;
int m,n;
cin>>t;
while(t--)
	{
vector<int> sum;
vector<int> g[112345];
int visited[112345]={};
	int a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		}
	int ar[112345];
	for(int i=1;i<=n;i++)
	{
	cin>>ar[i];
	}
for(int x=1;x<=n;x++)
	{
	vector <int> sta;
	sta.push_back(x);
	int s=ar[x];
	//cout<<"NEW GUY has sum "<<s<<"\n";
		if(visited[x]==0)
		{
		visited[x]=1;
		while(!sta.empty())
			{
				int c=*(--sta.end());
				//cout<<"C="<<c<<endl;
				sta.pop_back();
				//if(visited[c]==0)
					//{
				
				
				for(int i=0;i<g[c].size();i++)
					{
						if(visited[g[c][i]]==0)
							{
							//cout<<" un visited "<<g[c][i]<<endl;
							visited[g[c][i]]=1;
							sta.push_back(g[c][i]);
							s+=ar[g[c][i]];
							//cout<<" sum is now : "<<s<<endl;
							}
					}				
					//}	
			}
		}
	sum.push_back(s);
	}
sort(sum.begin(),sum.end());
cout<<*(--sum.end())<<endl;
}

}
