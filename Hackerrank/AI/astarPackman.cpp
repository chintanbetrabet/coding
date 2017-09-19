#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define ppi pair<pi,pi>
void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){

	priority_queue<pair<pi,pair<pi,pi> > > q;
	int n=grid.size(),m=grid[0].length();
	pi target=make_pair(-1,-1);
	pi parent[n][m];
	int visited[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{parent[i][j]=target;visited[i][j]=0;}

	q.push(make_pair(pi(0,0),ppi(pi(-1,-1),pi(pacman_r,pacman_c))));
	//cout<<q.top().second.first.first<<endl;
	
	int count=0;
	visited[pacman_r][pacman_c]=1;
	queue<pi> path;
	while(!q.empty())
	{
		count++;
		pair<pi,ppi> top=q.top();
		//cout<<"elements="<<q.size()<<endl;
		int gcost=top.first.second;
		//cout<<"current depth="<<-1*gcost<<endl;
		q.pop();
		//cout<<"SF= "<<top.second.first<<endl;
		
		pi par=top.second.first;
		pi me=top.second.second;
		int row=me.first,col=me.second;
//		cout<<" NODE is "<<row<<","<<col<<endl;
		path.push(me);
		parent[row][col]=par;
		visited[row][col]=1;
		if(grid[row][col]=='.') 
		{
			
			
			
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
//				cout<<"Added "<<row-1<<" "<<col<<endl;
				//q.push(make_pair(make_pair(0,gcost-1),make_pair(me,make_pair(row-1,col))));
				q.push(make_pair(make_pair(-1*abs(food_r-row+1)-1*abs(food_c-col),gcost-1),make_pair(me,make_pair(row-1,col))));
				visited[row-1][col]=1;
			}
			else
			{
//			cout<<"Did not add "<<row-1<<" "<<col<<endl;
			}
		}

		if(col>0)
		{
			if(grid[row][col-1]!='%'&&visited[row][col-1]==0)
			{
//			cout<<"Added "<<row<<" "<<col-1<<endl;
			//q.push(make_pair(make_pair(0,gcost-1),make_pair(me,make_pair(row,col-1))));
				
				q.push(make_pair(make_pair(-1*abs(food_r-row)-1*abs(food_c-col+1),gcost-1),make_pair(me,make_pair(row,col-1))));
				visited[row][col-1]=1;
			}  
				else
			{
//			cout<<"Did not add "<<row<<" "<<col-1<<endl;
			} 
		}


		if(col+1<c)
		{
			if(grid[row][col+1]!='%'&&visited[row][col+1]==0)
			{
//			cout<<"Added "<<row<<" "<<col+1<<endl;
			q.push(make_pair(make_pair(0,gcost-1),make_pair(me,make_pair(row,col+1))));
				
				q.push(make_pair(make_pair(-1*abs(food_r-row)-1*abs(food_c-col-1),gcost-1),make_pair(me,make_pair(row,col+1))));
				visited[row][col+1]=1;
			}
				else
			{
//			cout<<"Did not add "<<row<<" "<<col+1<<endl;
			}
			   
		}
		if(row+1<r)
		{
			if(grid[row+1][col]!='%'&&visited[row+1][col]==0)
			{
//cout<<"Added "<<row+1<<" "<<col<<endl;
				//q.push(make_pair(make_pair(0,gcost-1),make_pair(me,make_pair(row+1,col))));
				q.push(make_pair(make_pair(-1*abs(food_r-row-1)-1*abs(food_c-col),gcost-1),make_pair(me,make_pair(row+1,col))));
				visited[row+1][col]=1;
			}   
				else
			{
			//cout<<"Did not add "<<row+1<<" "<<col<<endl;
			}
		}

/*
		
		while(!q.empty()){
		pair<pi,ppi> mytop=q.top();
		me=mytop.second.second;
		cout<<"elements="<<q.size()<<endl;
		int gcost=top.first.second;
		cout<<"TOP = "<<me.first<<","<<me.second<<endl;
		cout<<"current depth="<<-1*gcost<<endl;
		q.pop();
		//cout<<"SF= "<<top.second.first<<endl;
		
		
		}
		*/


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

