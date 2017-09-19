#include <bits/stdc++.h>
using namespace std;

#define mp(a,b) pair<int,int>(a,b)
#define fi first
#define se second
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
        int N;cin>>N;
        int W;cin>>W;
        vector<int> vals;
        vector<int> weights;
        vector<pair<int,int> > items;
        for(int i=0;i<N;i++)
            {
                int v;
                cin>>v;
                vals.push_back(v);
            }
        for(int i=0;i<N;i++)
            {
                int v;
                cin>>v;
                weights.push_back(v);
            }
        for(int i=0;i<N;i++)
            {

             
                items.push_back(mp(weights[i],vals[i]));
            }
        sort(items.begin(),items.end());

        int knapsack[N][W+1]={};
        for(int i=0;i<N;i++)
        {
            knapsack[i][0]=0;
        }
                for(int i=1;i<=W;i++)
        {
        //cout<<"item is "<<items[0].first<<endl;
            if(i>=items[0].first)
            {
                knapsack[0][i]=items[0].second;
            }
            else
            {
                knapsack[0][i]=0;
            }
        }
        /*for(int i=0;i<N;i++)
        {
        for(int j=0;j<=W;j++)
        	{
        cout<<knapsack[i][j]<<" ";
        	}
        	cout<<endl;
        }*/
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(j<items[i].first)
                {
                    knapsack[i][j]=knapsack[i-1][j];
                }
                else
                {
                 knapsack[i][j]=max(knapsack[i-1][j],knapsack[i-1][j-items[i].first]+items[i].second);   
                }
            }
        }
        /*cout<<endl;
        for(int i=0;i<N;i++)
        {
        for(int j=0;j<=W;j++)
        	{
        cout<<knapsack[i][j]<<" ";
        	}
        	cout<<endl;
        }*/
        cout<<knapsack[N-1][W]<<endl;
	}
	return 0;
}
