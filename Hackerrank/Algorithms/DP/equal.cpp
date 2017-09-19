#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
unsigned long long int DP[3][10005];
void doDP()
{
    int values[]={1,2,5};
    for(int i=0;i<10005;i++)
        DP[0][i]=i/values[0];
    for(int v=1;v<3;v++){
    for(int i=0;i<10005;i++)
    {
        if(i<values[v])
        {
            DP[v][i]=DP[v-1][i];
        }
        else
        {
            DP[v][i]=min(DP[v-1][i],DP[v][i-values[v]]+1);
        }
    }
    }
}
unsigned long long int solve(vector<int> values)
{
    int minim=values[0];
    int maxim=values[0];
    unsigned long long int v=0;
    unsigned long long int v2=0;
    
    for(int i=0;i<values.size();i++)minim=min(minim,values[i]);
    for(int i=0;i<values.size();i++)maxim=max(maxim,values[i]);
    for(int i=0;i<values.size();i++)v+=DP[2][values[i]-minim];
    for(int i=0;i<values.size();i++)v2+=DP[2][values[i]];
    
    return min(v,v2);
}

int main() {
    int t,n;
    cin>>t;
    doDP();
    while(t--){
        cin>>n;
        vector<int> values(n,0);
        for(int i=0;i<n;i++)cin>>values[i];
        cout<<solve(values)<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

