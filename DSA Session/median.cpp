#include <queue>
#include <iostream>

/*

default priority_queue is MAX HEAP
*/

using namespace std;
int main() {
    priority_queue<int> maxl;
    priority_queue<int> minl;
    int t;cin>>t;
    int ln=0,rn=0;
    int mid;
    cin>>mid;
    cout<<mid<<".0"<<endl;
    int num=1;
    t-=1;
    while(t--)
        {
        num++;
        int v;
        cin>>v;
        if(v>mid)
            {
            rn++;
            maxl.push(-1*v);
            if(ln-rn<-1)
                {
             ln++;
                minl.push(mid);
                mid=(maxl.top())*-1;
                maxl.pop();
                rn--;
            }
        }
        else
            {
            ln++;
            minl.push(v);
            if(ln-rn>1)
                {
             rn++;
                maxl.push(-1*mid);
                mid=minl.top();
                minl.pop();
                ln--;
            }
        }
        
        if(num%2==0)
        {
            if(ln>rn)
                {
                if(((mid)+minl.top())%2==1)
                cout<<((mid)+minl.top())/2.0<<endl;
                else  cout<<((mid)+minl.top())/2<<".0"<<endl;
                    
            }
            else{
                if(((mid)-maxl.top())%2)
             cout<<((mid)-maxl.top())/2.0<<endl;  
                else cout<<((mid)-maxl.top())/2.0<<".0"<<endl;
            }
        }
        else
            {
            cout<<mid<<".0"<<endl;
        }
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

