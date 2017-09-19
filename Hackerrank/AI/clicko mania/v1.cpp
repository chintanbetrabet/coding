#include<bits/stdc++.h>
using namespace std;

#define DEPTH 2
//int visited[10][10];
void merge(vector<string> &grid);
int dfs(int row,int col,char color,vector<string> & grid, vector<vector<int> > &visited);

int sanity(vector<string>grid)
{
	vector< vector<int> > visited;
	for(int i1=0;i1<grid.size();i1++){
	vector<int> row;
	for(int j1=0;j1<grid[0].length();j1++)
	{
	row.push_back(0);
	}
	visited.push_back(row);
	}
	
	map<char,int> sing,cnt;
	for(int r=0;r<grid.size();r++)
		for(int c=0;c<grid[0].length();c++)
		{
		
		int compo=dfs(r,c,grid[r][c],grid,visited);
		cnt[grid[r][c]]+=compo;
		if(compo==1){
			sing[grid[r][c]]+=1;
		}
		}
	string colors="VIBGYOR";
	/*
	for(int i=0;i<7;i++)
		{
		if(cnt[colors[i]]==sing[colors[i]]&&cnt[colors[i]]>0)
			{
			return -12345678;
			}
		}
		*/
	return 0;

}

int dfs(int row,int col,char color,vector<string> & grid, vector<vector<int> > &visited)
{
	if(grid[row][col]!=color&& color!='-'||visited[row][col])return 0;
	//cout<<"CALLED on "<<row<<"  "<<col<<" "<<grid[row][col]<<endl;

	visited[row][col]=1;
	int components=1;
	if(row>0)
	{
		if(visited[row-1][col]==0&&grid[row-1][col]==grid[row][col])
			components+=dfs(row-1,col,color,grid,visited);
	}
	if(row<grid.size()-1)
	{
		if(visited[row+1][col]==0&&grid[row+1][col]==grid[row][col])
			components+=dfs(row+1,col,color,grid,visited);
	}
	if(col>0)
	{
		if(visited[row][col-1]==0&&grid[row][col-1]==grid[row][col])
			components+=dfs(row,col-1,color,grid,visited);
	}
	if(col<grid[0].length()-1)
	{
		if(visited[row][col+1]==0&&grid[row][col+1]==grid[row][col])
			components+=dfs(row,1+col,color,grid,visited);
	}
	grid[row][col]='-';
	return components;
}
void show(vector<string> grid)
{
	for(int i=0;i<grid.size();i++)
		cout<<grid[i]<<endl;
}
void gridcpy(vector<string> src,vector<string> &target)
{
	for(int i=0;i<src.size();i++)
		target[i]=src[i];
}
float gridScore(vector<string> grid)
{
	set<char> colorSet;
	float count=0.0;
	for(int j=0;j<grid[0].length();j++)
	{
		for(int i=0;i<grid.size();i++)
		{
			if(grid[i][j]!='-'){
				count+=1.0;
				colorSet.insert(grid[i][j]);
			}
		}
	}


	////cout<<"colorset size="<<colorSet.size()<<" count="<<count<<"  elements:  "<<5*colorSet.size()<<" "<<1*(count)*colorSet.size()<<" result: "<<endl;
	float mysc=(5*colorSet.size()-1*(count/20.0)*colorSet.size());
	mysc=(1-count)*5*colorSet.size()+sanity(grid);
	////cout<<"SCORE ="<<mysc<<endl<<endl;
	return mysc;
}
float score(vector<string>  &srcgrid,int search_level,int limit_level)
{
	////cout<<" levels"<<search_level<<" "<<limit_level<<endl;
	
	
	vector< vector<int> > visited;
	for(int i1=0;i1<srcgrid.size();i1++){
		vector<int> row;
		for(int j1=0;j1<srcgrid[0].length();j1++)
		{
			row.push_back(0);
		}
		visited.push_back(row);
	}

	vector<string> grid(srcgrid.size());
	float mySc=-10000000.0;
	int r=srcgrid.size(),c=srcgrid[0].length();
	
	int aR=r-1,aC=0;
		int count_moves=0;
		gridcpy(srcgrid,grid);
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
	{
	if(visited[i][j]==0)
		{
		count_moves+=1;
		dfs(i,j,srcgrid[i][j],grid,visited);
		}
	}
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
	visited[i][j]=0;
	
	for(int i=0;i<r;i++)
	{

		for(int j=0;j<c;j++)
		{

			if(visited[i][j]==0&&srcgrid[i][j]!='-'){
				////cout<<search_level<<" INIT call on "<<i<<" "<<j<<endl;
				gridcpy(srcgrid,grid);

				int compo=dfs(i,j,grid[i][j],grid,visited);
				if(compo<2)continue;
				//cout<<"END\n";

				//show(grid);
				merge(grid);
				////cout<<endl;
				//show(grid);
				if(search_level>=min(limit_level,count_moves-1))
				{
					float loc=gridScore(grid);
					//cout<<"LOCAL SCORE ="<<loc<<endl;
					if(mySc < loc)
					{
						aR=i;aC=j;
						mySc=loc;
					}
				}
				else
				{

					float loc=score(grid,search_level+1,limit_level);
					//cout<<search_level<<"FINAL SCORE ="<<i<<"  "<<j<<"  "<<loc<<endl;
					if(mySc < loc)
					{
						aR=i;aC=j;
						mySc=loc;
					}

				}
			}
		}
	}
	if(search_level==0)
	{
		cout<<aR<<" "<<aC<<endl;
		//aR=19;aC=0;
		for(int i1=0;i1<srcgrid.size();i1++)for(int j1=0;j1<srcgrid[0].length();j1++)visited[i1][j1]=0;
		//srcgrid[aR][aC]='';
		//show(srcgrid);
		//cout<<"GONNA SHOW\n";
		dfs(aR,aC,srcgrid[aR][aC],srcgrid,visited);
		//show(srcgrid);
		merge(srcgrid);
		//cout<<endl;
		//show(srcgrid);
	}
	return mySc;
}
void nextMove(int x, int y, int color, vector <string> &grid){
	score(grid,0,DEPTH);
}
int main(void) {

	int x,y,k;
	cin >> x >> y >> k;
	vector <string> grid;

	for(int i=0; i<x; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	nextMove( x, y, k, grid);
	//nextMove( x, y, k, grid);

	return 0;
}
void merge(vector<string> &grid)
{

	/*//cout<<"BEFORE \n";
	  for(int i=0;i<grid.size();i++)
	//cout<<grid[i]<<endl;
	//cout<<"\n\nAfter collapsing:\n"<<endl;
	 */
	for(int j=0;j<grid[0].length();j++){
		queue<int> dots;
		for(int i=grid.size()-1;i>=0;i--)
		{

			if(grid[i][j]=='-')
			{
				dots.push(i);
			}
			else if(!dots.empty()){
				int i1=dots.front();
				dots.pop();
				char temp=grid[i][j];
				grid[i][j]=grid[i1][j];
				grid[i1][j]=temp;
				dots.push(i);
			}

		}
	}
	queue<int> swap_target;
	for(int j=0;j<grid[0].length();j++)
	{
		int valid=0;
		for(int i=0;i<grid.size();i++)
		{
			if(grid[i][j]!='-'){valid=1;break;}
		}
		if(valid==0)
		{
			swap_target.push(j);
		}
		else if(!swap_target.empty())
		{
			int start=swap_target.front();
			if(start<j){
				swap_target.pop();
				for(int i=0;i<grid.size();i++)
				{
					char temp=grid[i][j];
					grid[i][j]=grid[i][start];
					grid[i][start]=temp;
				}
				swap_target.push(j);
			}
		}
	}

	/*	for(int i=0;i<grid.size();i++)
	//cout<<grid[i]<<endl;
	 */

}

