#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)
int bellout[401][401];
int mv=1000000000;
void floydWarshall(int graph[401][401],int n)
{
	loop(i,401)loop(j,401)bellout[i][j]=graph[i][j];
	loop(k,n)bellout[k][k]=0;
	loop(i,n)loop(x,n)bellout[i][x]=min(graph[i][x],bellout[i][x]);
	loop(source,n)loop(destination,n)
	{
		loop(mid,n)
		{
			
			//if(bellout[source][mid] !=mv && bellout[mid][destination] != mv)
			
			{
				
				bellout[source][destination]=min(bellout[source][destination],bellout[source][mid]+bellout[mid][destination]);
			}
		}
	}
	loop(source,n)loop(destination,n)
	{
		loop(mid,n)
		{
			
			if(bellout[source][mid] !=mv && bellout[mid][destination] != mv)
			
			{
				
				bellout[source][destination]=min(bellout[source][destination],bellout[source][mid]+bellout[mid][destination]);
			}
		}
	}

	//return bellout
}




int main()
{
	int t=1;
	//cin>>t;
	int a0;
	//loop(a0,t)
	//{
	int m,n;
	cin>>n>>m;
	int graph[401][401];
	loop(i,401)loop(j,401)
	{
		if(i!=j)graph[i][j]=mv;
		else graph[i][j]=0;
	}
	int a1;
	loop(a1,m)
	{
		int x,y,r;
		cin>>x>>y>>r;
		graph[x][y]=(r);
	}
	floydWarshall(graph,n+1);
	int s;
	cin>>s;
	loop(x,s){
			int p,q;
			cin>>p>>q;
			if (bellout[p][q] == mv)
				cout<< -1<<endl;
			else  cout<<bellout[p][q]<<endl;
		}
	
	}



