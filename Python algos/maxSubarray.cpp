#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)
int maxSubarray(vector<int> nums,int n)
{
	int  curr=0;
	int pos=0;
	int ms=0,  me=0,  st=0,  end=0,  maxv=nums[0];
	loop(i,n)
	{
		int x=nums[i];
		if (curr>0 && x >=0)
		{
			curr=curr+x;
			end+=1;
			pos+=x;
			if (curr> maxv)
			{
				maxv=curr;
				ms=st;
				me=end;
			}
		}
		else{
			if (curr <=0 && x >=0)
			{
				curr=x;
				pos+=x;
				if( curr> maxv){
					maxv=curr;
					ms=st;
					me=end;
				}
				st=i;
				end=i;
			}
			else{
				if (curr <=0 && x <=0)
				{
					curr=0;
					st=i;
					end=i;
					if (curr> maxv)
					{
						maxv=curr;
						ms=st;
						me=end;
					}
				}
				else
					if (curr >=0 && x <=0)
					{
						if (curr> maxv){
							maxv=curr;
							ms=st;
							me=end;
							}
							curr=curr+x;
							end+=1;
							
						
					}
			}
		}
	}
	int fl=1,ma1=-1000000000;
	for(int i=0;i<n;i++)
	{
	if(nums[i]>0)fl=0;
	ma1=max(ma1,nums[i]);
	}
	if(fl==1)
	{
	cout<<"all negative";
	cout<<ma1<<"\n";
	}
	return n;
	cout<<" max is from : "<<ms<<" to "<<me<<endl;
	for (int i=ms;i<me+1;i++)
		nums[i]=(nums[i]*-1);
	int  cnt=0;
	for (int i=0;i<n;i++)
	{
		if (nums[i]==-1)
			cnt+=1;
	}
	return cnt;
}
int main()
{
	int t,n;
	vector<int> nums;
	cin>>t;
	while (t>0){
		t-=1;
		cin>>n;
		loop(i,n)
		{
			int v;
			cin>>v;
			nums.push_back(v);
		}
		loop(i,n)
			nums[i]=pow(-1,nums[i]);
		cout<< (maxSubarray(nums,n))<<endl;
	}           
}
