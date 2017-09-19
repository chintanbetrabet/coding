#include <bits/stdc++.h>
using namespace std;

#define mp(a,b) pair<int,int>(a,b)
#define fi first
#define se second

    int numDecodings(string s) {
        int n=s.length();
long long dp[112345]={};
        dp[0]=1;
        dp[1]=1;
        int fl=1;
        if(s.length()==0||s[0]=='0')return 0;
        for(int i=1;i<s.length();i++)
        {
            int num=(s[i-1]-'0')*10+(s[i]-'0');
           if(s[i]=='0' && (s[i-1]>'2' || s[i-1] =='0'))
           {
               fl=0;
           }
          if(i>=2)
            {
                if(s[i-1]=='0' && (s[i-2]!='1' && s[i-2]!='2'))
                {
                    cout<<"fault at i="<<i<<" at i-1"<<s[i-1]<<" at i-2 "<<s[i-2]<<endl;
                    //break;
                    fl=0;
                }
            }
            if(num>26 || s[i-1]=='0')
            {
            //    cout<<"on symbol :"<<s[i]<<"enter loop1\n";
                dp[i+1]=dp[i];
            }
            else if(s[i]=='0' )
            {
                dp[i+1]=dp[i-1];
            }
            else 
            {
              //  cout<<"on symbol :"<<s[i]<<"enter loop2\n";
                
                dp[i+1]=dp[i-1]+dp[i];
            }
            
        }
    
        return dp[n]*fl;
        }

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
        string s;
        cin>>s;

        cout<<numDecodings(s)<<endl;
	}
	return 0;
}
