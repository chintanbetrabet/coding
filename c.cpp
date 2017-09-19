#include <bits/stdc++.h>

using namespace std;


int circularWalk(int n, int s, int t, int r_0, int g, int seed, int p){
	int R[n];
	R[0]=r_0;
	vector<int> graphs[n];
	for(int i=1;i<n;i++)
	{
		R[i]=(R[i-1]*g+seed)%p;
	}
	int dist[n];
	for(int i=0;i<=n;i++)
	{
		dist[i]=n+1;
	}
	dist[s]=0;
	int found=-1;
	int minedFlag[n]={};
	set<int> mined;
	set<int> tobeadded;
	mined.insert(s);
	int j1=0;
	for(int k=1;k<=R[j1];k++)
	{
		tobeadded.insert((j1+k+n)%n);
		tobeadded.insert((j1-k+n)%n);
	}
	minedFlag[s]=1;
	tobeadded.insert(s);
	while(!tobeadded.empty())
	{
		tobeadded.clear();
		set<int>  :: iterator sti;
		for(sti=mined.begin();sti!=mined.end();++sti)        
		{
            j1=*sti;
			for(int k=1;k<=R[j1];k++)
			{
				dist[(j1+k+n)%n]=min(dist[(j1+k+n)%n],dist[j1]+1);
                if(minedFlag[(j1+k+n)%n]==0)
                    {
                    tobeadded.insert(((j1+k+n)%n));
                    minedFlag[(j1+k+n)%n]=1;
                }
				dist[(j1-k+n)%n]=min(dist[(j1-k+n)%n],dist[j1]+1);
                if(minedFlag[(j1-k+n)%n]==0)
                    {
                    tobeadded.insert(((j1-k+n)%n));
                    minedFlag[(j1-k+n)%n]=1;
                }
			}
		}
        mined.clear();
        for(sti=tobeadded.begin();sti!=tobeadded.end();++sti)
            {
            mined.insert(*sti);
        }
	}

	if(dist[t]==n+1)return -1;
	//  cout<<endl;

	return dist[t];
	// Complete this function
}

int main() {
	int n;
	int s;
	int t;
	cin >> n >> s >> t;
	int r_0;
	int g;
	int seed;
	int p;
	cin >> r_0 >> g >> seed >> p;
	int result = circularWalk(n, s, t, r_0, g, seed, p);
	cout << result << endl;
	return 0;
}

