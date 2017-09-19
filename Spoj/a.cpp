#include<bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
int N;
cin>>N;
while (N>0)
	{
	
	set<pair<int,int> > valset;
	loop(i,N){
		loop(j,N){
			valset.insert(pair<int,int>(i,j));
			}
		}
	int sq=0;
	loop(i,N){
		loop(j,N){
			int curri=i;
			int currj=j;
			pair<int,int> search;
			search.first=curri;
			search.second=currj;
			while (valset.find(search)!=valset.end())  {
				curri+=1;
				currj+=1;
				search.first=curri;
				search.second=currj;
				sq+=1;
				}
			}
		}
	cout<<sq<<endl;
	cin>>N;
	}
}
