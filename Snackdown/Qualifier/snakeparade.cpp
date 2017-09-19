#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
    	stack<char> st;
        string s;
        
        int n;cin>>n;
        cin >> s;
        int fl=1;
        for(int i=0;i<s.length() && fl==1;i++)
        {
        	char let=s[i];
        	if(let=='.')continue;
        	if(let=='H')
        	{
        	//cout<<"added to stack\n";
        	if(!st.empty())
        		{
        		fl=0;break;
        		}
        	st.push(let);
        	}
        	else if (st.empty())
			{
			//cout<<"empty stack asked pop\n";
			fl=0;break;
			}
		else if(let=='T'){
		//cout<<"pop from stack\n";
		st.pop();
		}
			
        	
        	
        }
        
            if(!st.empty()){fl=0;//cout<<"Stack non empty\n";
            }
           // else cout<<"Stack empty\n";
            if(fl==1)
    {
    cout<<"Valid\n";
    }
    else
    {
    cout<<"Invalid\n";
    }

    }
    
    
    return 0;
}
