#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	int n,k;
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		int va;
		cin>>va;
		v.push_back(va);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		cout<<endl<<i<<"    "<<v[i];
	}
}