#include<bits/stdc++.h>
using namespace std;

#define pv pair<vector<int>,vector<int> >
#define pi pair<int,int>
#define vi vector<int>
#define in2r(ind,k) ind/k
#define in2c(ind,k) ind%k
#define rc2in(r,c,k) r*k+c
#define H heuristic
#define mp make_pair

int heuristic(vi v)
{
	int n=v.size();
	int inv=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i]>v[j])inv+=1;
		}
	}
	return inv;
}

void vecCopy(vi src,vi &dest)
{
	for(int i=0;i<src.size();i++)
	{
		dest.push_back(src[i]);
	}
}
void show(vi tab,int k)
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
			cout<<tab[i*k+j]<<" ";
		cout<<endl;
	}
	cout<<endl;

}
int main(void) {
	int n;
	cin>>n;
	set<vi> stateVisited;
	vi state(n*n);
	string direc[]={"UP","DOWN","LEFT","RIGHT"};
	for(int s=0;s<n*n;s++)cin>>state[s];

	priority_queue<pair<int,pv> >pq; 
	vi moves;
	pq.push(mp(-1*heuristic(state),mp(moves,state)));

	stateVisited.insert(state);

	while(!pq.empty())
	{
		pair<int,pv> top=pq.top();
		vi mystate=top.second.second;
		vi mymoves=top.second.first;
		pq.pop();
		int dis=heuristic(mystate);
		cout<<"HEURISTIC "<<dis<<endl;
		show(mystate,n);
		if(heuristic(mystate)==0)
		{
			cout<<mymoves.size();
			for(int i=0;i<mymoves.size();i++)
				cout<<direc[mymoves[i]-1]<<endl;
			break;
		}

		int steps=mymoves.size();
		int zeroPos=0;
		for(int i=0;i<n*n;i++)if(mystate[i]==0)zeroPos=i;
		int cr=in2r(zeroPos,n);
		int cc=in2c(zeroPos,n);

		if(cr>0){
			vi stateCopy;
			vi movesCopy;
			vecCopy(mystate,stateCopy);
			vecCopy(mymoves,movesCopy);
			movesCopy.push_back(1);
			int din=rc2in(cr-1,cc,n);
			int temp=stateCopy[din];
			stateCopy[din]=stateCopy[zeroPos];
			stateCopy[zeroPos]=temp;
			if(stateVisited.find(stateCopy)==stateVisited.end()){
				pq.push(mp((-1*heuristic(stateCopy)-steps),pv(movesCopy,stateCopy)));
				stateVisited.insert(stateCopy);
				cout<<"ADDED UP TO:"<<endl;
				show(stateCopy,n);
			}
		}



		if(cr<n-1){
			vi stateCopy;
			vi movesCopy;
			vecCopy(mystate,stateCopy);
			vecCopy(mymoves,movesCopy);
			movesCopy.push_back(2);
			int din=rc2in(cr+1,cc,n);
			int temp=stateCopy[din];
			stateCopy[din]=stateCopy[zeroPos];
			stateCopy[zeroPos]=temp;
			if(stateVisited.find(stateCopy)==stateVisited.end()){
				pq.push(mp((-1*heuristic(stateCopy)-steps),pv(movesCopy,stateCopy)));
				stateVisited.insert(stateCopy);
				cout<<"ADDED DOWN TO:"<<endl;
				show(stateCopy,n);
			}
		}

		if(cc>0){
			vi stateCopy;
			vi movesCopy;
			vecCopy(mystate,stateCopy);
			vecCopy(mymoves,movesCopy);
			movesCopy.push_back(3);
			int din=rc2in(cr,cc-1,n);
			int temp=stateCopy[din];
			stateCopy[din]=stateCopy[zeroPos];
			stateCopy[zeroPos]=temp;
			if(stateVisited.find(stateCopy)==stateVisited.end()){
				pq.push(mp((-1*heuristic(stateCopy)-steps),pv(movesCopy,stateCopy)));
				stateVisited.insert(stateCopy);
				cout<<"ADDED RIGHT TO:"<<endl;
				show(stateCopy,n);
			}
		}


		if(cc<n-1){
			vi stateCopy;
			vi movesCopy;
			vecCopy(mystate,stateCopy);
			vecCopy(mymoves,movesCopy);
			movesCopy.push_back(4);
			int din=rc2in(cr,cc+1,n);
			int temp=stateCopy[din];
			stateCopy[din]=stateCopy[zeroPos];
			stateCopy[zeroPos]=temp;
			if(stateVisited.find(stateCopy)==stateVisited.end()){
				pq.push(mp((-1*heuristic(stateCopy)-steps),pv(movesCopy,stateCopy)));
				stateVisited.insert(stateCopy);
				cout<<"ADDED RIGHT TO:"<<endl;
				show(stateCopy,n);
			}
		}


	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	return 0;
}

