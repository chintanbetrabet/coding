 #include<bits/stdc++.h>
 using namespace std;
 
 bool optimizedwordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
 
 
 map<string,bool> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
         if((s).length()==0)
            return true;
    
       cout<< "Call on "<<s<<endl;
       set<string> wordSet;
       for (int i=0;i<wordDict.size();i++)
       {
        wordSet.insert(wordDict[i]);   
       }
        if(wordSet.find(s)!=wordSet.end())
        {
        mp[s]=true;
        return true;
        }
       string subleft;
        for (int i=0;i<s.length();i++)
        {
            string sub=s.substr(0,i);
            if (wordSet.find(sub)!=wordSet.end())
            {
                cout<< "matched on "<<sub<<endl;
                subleft=s.substr(i,s.length()-1);
                 if (subleft.length()==0)
                 {
                     cout<< "matched null on "<<endl;
                        return true;
                 }
                else if (mp.find(subleft)!=mp.end()){
                     cout<< "matched map on "<<subleft<<endl;
                   return mp[subleft];
                }
               else if (wordBreak(subleft,wordDict)){
                    cout<< "matched call on "<<subleft<<endl;
                    mp[subleft]=true;
                    return true;
                }
                else
                {
                mp[subleft]=false;
                }
            }
        }
       // mp[s]=false;
        return false;
        
    }
int main()
{
string s;
cin>>s;
int t;
cin>>t;
vector<string> v;
for(int i=0;i<t;i++)
	{
	string x;
	cin>>x;
	v.push_back(x);
	}
cout<<wordBreak(s,v);
}
