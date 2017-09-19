#include<bits/stdc++.h>

using namespace std;
int sets[112345];
int size[112345];
void initialize_set()
{
	for(int i=0;i<112345;i++)
	{
		sets[i]=i;
		size[i]=1;
	}
}
int findroot(int a)
{
	int i=a;
	while(sets[i]!=i)
	{
	i=sets[i];
	}
	return i;
}
void union_set(int a,int b)
{
//cout<<"merging "<<a<<"  "<<b<<"\n";
	if(size[a]>size[b])
	{
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
        /*if(size[findroot(a)]<n-1)
            return true;
        return false;*/
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
		sets[findroot(a)]=findroot(b);
       /* if(size[findroot(b)]<n-1)
            return true;
        return false;*/
	}	
}
bool find(int a,int b)
{
	return findroot(a)==findroot(b);
}
int main()
{
int t;
int m,n;
cin>>t;
while(t--)
	{
vector<int> sum;
int ar[112345]={};
for (int i=0;i<112345;i++)
sum.push_back(0);
	cin>>n>>m;
	initialize_set();

	while(m--)
		{
		int a,b;
		cin>>a>>b;
		union_set(a,b);
		}
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++)
		{
		//cout<<"\n in group "<<i<<":";
			for(int j=1;j<=n;j++)
				{
				if(findroot(j)==i)
					{
					sum[i]=sum[i]+ar[j];
					}
				}
		}
	for(int i=1;i<=n;i++)
		{
		//cout<<"\n in group sum"<<i<<":"<<sum[i];			
		}
	sort(sum.begin(),sum.end());
	cout<<*(--sum.end())<<endl;
	}
}
