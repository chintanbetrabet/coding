#include<bits/stdc++.h>
using namespace std;
#define loop(i,st,n) for(int i=st;i<n;i++)
#define leep(i,st,n) for(int i=st;i<=n;i++)
#define ll long long
#define mp(a,b) pair<int,int>(a,b)
#define MAX_SIZE 5001

int isP[MAX_SIZE][MAX_SIZE];
int init(string s)
{
for(int i=0;i<MAX_SIZE;i++)
for(int j=0;j<MAX_SIZE;j++)
isP[i][j]=0;
for(int i=0;i<MAX_SIZE;i++)isP[i][i]=1;
for(int i=0;i<MAX_SIZE-1;i++)
	{
	if(s[i]==s[i+1])
		{
		isP[i][i+1]=1;
		}
	}

}

int getpalins(string s)
{
init(s);
//cout<<"SIZE="<<s.length()<<endl;
for(int l=2;l<s.length();l++)
	{
		for(int j=0;j+l<s.length();j++)
			{
				if(s[j]==s[j+l])
					{
					isP[j][j+l]=isP[j+1][j+l-1];
					isP[j+l][j]=isP[j+1][j+l-1];
					}
				else
				{
					isP[j][j+l]=0;
					isP[j+l][j]=0;
				}
			}
	}

}

int mindisA[MAX_SIZE];
int mindis(int s)
{
int assign=1000000;
  for(int i=0;i<s;i++)
  	{
  		if(isP[s-1][i]==1)
  		{
  		assign=min(assign,mindisA[i]+1);
  		}
  	}
  mindisA[s]=assign;
}
int main()
{
int t,n;
cin>>t;
while(t--)
{
string s1;
cin>>n;
cin>>s1;
getpalins(s1);
int edges=0;
for(int i=0;i<=n;i++)
	{
	mindisA[i]=i;
	}
for(int i=2;i<=n;i++)
	{
	mindis(i);
	}
cout<<mindisA[n]-1<<endl;
}	

}

