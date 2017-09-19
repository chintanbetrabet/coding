#include <bits/stdc++.h>

using namespace std;
bool palin(string s)
    {
    string s1="";
    for(int i=s.length()-1;i>=0;i--)
        {
        s1=s1+s[i];
    }
    return s1==s;
}
#define SI(l,it) for(set<string> :: iterator it=l.begin();it!=l.end();++it)
#define L(i,s,n) for(int i=s;i<n;i++)

    
   
    


vector < int > propertyOfString(string s0){
    vector<int> v1;
    for(int iter=1;iter<=s0.length();iter++)
        {
        string s=s0.substr(0,iter);
    set<string> T,G;
    L(i,0,s.length())
        {
        L(j,i+1,s.length()+1){
            if (palin(s.substr(i,j)))
                T.insert(s.substr(i,j));
        }
    }
    
    SI(T,x)
        {
        L(i,0,(*x).length()){
            L(j,i+1,(*x).length()+1)
                {
                G.insert((*x).substr(0,j));
            }
        }
    }
        v1.push_back(G.size());
    }
    
    // Complete this function
    return v1;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < int > result = propertyOfString(s);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}

