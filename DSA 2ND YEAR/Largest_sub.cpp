#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
#include<map>
#include<stdio.h>
using namespace std;


int main()
{
	char s1[212345],s2[212345];
	string maxS,str1,str2;
	gets(s1);
	gets(s2);
	int l1=0,l2=0;
	for(int i=0;i>-1;i++)
		{
			str1+=s1[i];
			if(str1[i]==0)
			break;
			l1++;
		}
	for(int i=0;i>-1;i++)
		{
			str2+=s2[i];
			if(str2[i]==0)
			break;
			l2++;
		}
	//cout<<str1<<" "<<str2<<" ";
	//cout<<str1[sizeof(str1)-1];
	int hi=l1,lo=0;
	int fm=0;
	while(hi>=lo)
	{
		
	//	cout<<"\nhi "<<hi<<" lo="<<lo;getch();
		int mid=(hi+lo)/2;
		map<string,int> p;
		for(int i=0;str1[i+mid-1];i++)
		{
			pair<string,int> t;
		//cout<<(str1.substr(i,mid))<<" ";
			t.first=(str1.substr(i,mid));
			t.second=mid;
			p.insert(std::pair<string,int>((str1.substr(i,mid)),mid));
		}
		int found=0,i;
		//cout<<"\nsearched:";
		for(i=0;str2[i+mid-1];i++)
		{
		//cout<<str2.substr(i,mid)<<"  ";
			if(p.find((str2.substr(i,mid)))!=p.end())
					{
						found=1;
						break;
					}
		}
		if(found==0)
		{
			hi=mid-1;
		}
		else {
		
		//	cout<<"\nFOUND "<<str2.substr(i,mid);
			fm=mid;
			maxS=str2.substr(i,mid);
		lo=mid+1;
			}
	}
	if(maxS[0]==' ')
	{
		maxS=maxS.substr(1,fm-1);
	}
	cout<<"\n"<<fm<<"\n"<<maxS;

	

}