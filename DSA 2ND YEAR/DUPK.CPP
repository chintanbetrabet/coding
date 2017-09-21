#include<iostream>
#include<map>
#include<math.h>
using namespace std;
int main()
{
	int ar[100];
	int s,k;
	cin>>s>>k; map<int,int> m;
	int flag=0,i=0;
	
	cin>>ar[i];
		m.insert(std::pair<int,int>(ar[i],ar[i]));
	for(i=1;i<k;i++){
		cin>>ar[i];
		if(m.find(abs(k-ar[i]))!=m.end())
		{
				flag=1;
			break;
			
			//m.erase(ar[i-k]);
		}
		else
		{
			m.insert(std::pair<int,int>(ar[i],ar[i]));
		
		}
	
		}
		if(flag==1)cout<<"TRUE";
		else cout<<"FALSE";

}