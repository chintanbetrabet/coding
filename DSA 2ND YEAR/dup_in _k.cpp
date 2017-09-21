#include<iostream>
#include<map>
using namespace std;
int main()
{
	int ar[100];
	int s,k;
	cin>>s>>k; map<int,int> m;
	int flag=0;
	for(int i=0;i<k;i++){
		cin>>ar[i];
		if(m.find(ar[i])!=m.end())
		{
			m.insert(std::pair<int,int>(ar[i],ar[i]));
			m.erase(ar[i-k]);
		}
		else
		{
			cout<<"FALSE";flag=1;
			break;
		}
	
		}

	for(int i=k;i<s&&flag==0;i++)
	{
		cin>>ar[i];
		if(m.find(ar[i])!=m.end())
		{
			m.insert(std::pair<int,int>(ar[i],ar[i]));
			m.erase(ar[i-k]);
		}
		else
		{
			cout<<"FALSE";flag=1;
			break;
		}
	}
	if(flag==0)
	cout<<"TRUE";
}