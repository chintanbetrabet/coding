#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll candies(ll n, vector <ll> arr) {
    vector<ll> ans(n,0);
    priority_queue< pair<ll,ll> > pq;
    for(int i=0;i<arr.size();i++)
    {
        pq.push(make_pair(-1*arr[i],i));
    }
    while(!pq.empty())
    {
        ll ele=-1*pq.top().first;
        ll index=pq.top().second;
        pq.pop();
        /*
        if(index>0)maxN=max(arr[index-1],maxN);
        if(index<n-1)maxN=max(arr[index+1],maxN);
        
        if(index>0)minN=min(arr[index-1],minN);
        if(index<n-1)minN=min(arr[index+1],minN);
        */
        ll maxC=0;
        if(index>0&&arr[index-1]<ele)maxC=max(ans[index-1],maxC);
        if(index<n-1&&arr[index+1]<ele)maxC=max(ans[index+1],maxC);
        
        /*
        int lv=(index>0)
        int minC=n+1;
        int rule;
        if(index>0)minC=min(ans[index-1],minC);
        if(index<n-1)minC=min(ans[index+1],minC);
        if(ele<=minN){ans[index]=1;rule=2;}
        else {ans[index]=maxC+1;rule=3;}
        */
        ans[index]=maxC+1;
        //cout<<" assigned to index "<<index<<" "<<ans[index]<< " using rule "<<rule<<endl;
    }
    ll sum=0;
    for(int i=0;i<n;i++)
    {
    	cout<<ans[i]<<" "<<sum<<endl;
        sum+=ans[i];
    }
    return sum;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    ll result = candies(n, arr);
    cout << result << endl;
    return 0;
}

