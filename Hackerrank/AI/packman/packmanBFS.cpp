#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){

	queue<pair<pi,pi> > q;
	int n=grid.size(),m=grid[0].length();
	pi target=make_pair(-1,-1);
	pi parent[n][m];
	int visited[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{parent[i][j]=target;visited[i][j]=0;}

	q.push(make_pair(pi(-1,-1),pi(pacman_r,pacman_c)));
	int count=0;
	visited[pacman_r][pacman_c]=1;
	queue<pi> path;
	while(!q.empty())
	{
		count++;
		pair<pi,pi> top=q.front();

		q.pop();
		pi par=top.first;
		pi me=top.second;
		int row=me.first,col=me.second;
		path.push(me);
		parent[row][col]=par;

		if(grid[row][col]=='.') 
		{
			cout<<count<<endl;
			while(!path.empty())
			{
			cout<<path.front().first<<" "<<path.front().second<<endl;
			path.pop();	
			}
			int d=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
				{
					//printf("%d,%d : visited=%d, parent:%d,%d\n",i,j,visited[i][j],parent[i][j].first,parent[i][j].second);
				}
			}
			
			pi mypar=par;
			stack<pi> st;
			st.push(make_pair(row,col));
			while(mypar!=target)
			{
				char ch;cin>>ch;
				st.push(mypar);
				mypar=parent[mypar.first][mypar.second];
			}
			cout<<st.size()-1<<endl;
			while(!st.empty())
			{
				cout<<st.top().first<<" "<<st.top().second<<endl;
				st.pop();
			}
			break;
		}
		if(row>0)
		{
			if(grid[row-1][col]!='%'&&visited[row-1][col]==0)
			{
				q.push(make_pair(me,make_pair(row-1,col)));
				visited[row-1][col]=1;
			}
		}

		if(col>0)
		{
			if(grid[row][col-1]!='%'&&visited[row][col-1]==0)
			{
				q.push(make_pair(me,make_pair(row,col-1)));
				visited[row][col-1]=1;
			}   
		}


		if(col+1<c)
		{
			if(grid[row][col+1]!='%'&&visited[row][col+1]==0)
			{
				q.push(make_pair(me,make_pair(row,col+1)));
				visited[row][col+1]=1;
			}   
		}
		if(row+1<r)
		{
			if(grid[row+1][col]!='%'&&visited[row+1][col]==0)
			{
				q.push(make_pair(me,make_pair(row+1,col)));
				visited[row+1][col]=1;
			}   
		}










	}

	//your logic here
}
int main(void) {

	int r,c, pacman_r, pacman_c, food_r, food_c;

	cin >> pacman_r >> pacman_c;
	cin >> food_r >> food_c;
	cin >> r >> c;
	vector <string> grid;

	for(int i=0; i<r; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	nextMove( r, c, pacman_r, pacman_c, food_r, food_c, grid);

	return 0;
}

