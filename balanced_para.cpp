#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
    	stack<char> st;
        string s;
        cin >> s;
        int fl=1;
        for(int i=0;i<s.length() && fl==1;i++)
        {
        	char let=s[i];
        	if(let=='(' || let=='{' || let =='[')
        	{
        	st.push(let);
        	}
        	else if(st.empty())
        	{
        	fl=0;
        	}
        	else if(let==')')
        	{
        	if(st.top()=='(')
        		{
        		st.pop();
        		}
        	}
        	else if(let=='}')
        	{
        	if(st.top()=='{')
        		{
        		st.pop();
        		}
        	}
        	        	else if(let==']')
        	{
        	if(st.top()=='[')
        		{
        		st.pop();
        		}
        	}
        	
        }
            if(!st.empty())fl=0;
            if(fl==1)
    {
    cout<<"YES\n";
    }
    else
    {
    cout<<"NO\n";
    }

    }
    
    
    return 0;
}
