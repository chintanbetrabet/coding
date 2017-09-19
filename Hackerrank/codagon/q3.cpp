#include <bits/stdc++.h>

using namespace std;

#define ITEMS int
#define CURRENT int
#define COST long long 
#define STARTED int
#define mp make_pair
#define pi pair<int,int>
#define ppi pair<int,pair<int,int > >
#define ll long long

long minimumTime(vector <int> b, int m, int k) {
   
    vector<int> indices;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]==1)indices.push_back(i);
    }

    ll cost=indices[0];
    for(int i=1;i<m;i++)
    {
    cost+=(indices[i]-indices[i-1])*(i*k);
    }
    cout<<"cost 0"<<cost<<endl;
    long long minc=cost;
    for(int i=m;i<indices.size();i++)
    {
    cost-=indices[i-m]+m*k;
    cost+=(indices[i]-indices[i-1])*(m-1)*k;
    cout<<"cost "<<i<<cost<<endl;
    minc=min(minc,cost);
    }
    return minc;
    return -1;
    // Complete this function
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for(int b_i = 0; b_i < n; b_i++){
       cin >> b[b_i];
    }
    long result = minimumTime(b, m, k);
    cout << result << endl;
    return 0;
}

