#include <bits/stdc++.h>

using namespace std;

int DP[100][100][100] ;//Start*prevHold*leftTransactions;
#define L(i,n) for(int i=0;i<n;i++)

int doDP(int start,int end,int hold,int transactionsLeft,vector<int> &prices)
{

if(transactionsLeft<=0)return 0;

if(end==start && hold!=0)
	{
	return max(prices[end]-prices[hold-1],0);
	}
if(end==start && hold==0)return 0;

if(DP[start][hold][transactionsLeft]==-1){
//BUY || SELL || HOLD
if(hold!=0) {//SELL or HOLD
DP[start][hold][transactionsLeft]= max(0,max(prices[start]-prices[hold-1]+doDP(start+1,end,0,transactionsLeft-1,prices),doDP(start+1,end,hold,transactionsLeft,prices)));
}
else
{
DP[start][hold][transactionsLeft]= max(0,max(doDP(start+1,end,start+1,transactionsLeft,prices),doDP(start+1,end,hold,transactionsLeft,prices)));
}
}
return DP[start][hold][transactionsLeft];
}


int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
        /*
        cout<<"Break up of the deals:"<<endl;
        L(i,n)
        {
        cout<<"Starting on day:"<<i<<endl;
        	L(j,n)
        	{
        	cout<<"Starting on day:"<<i<<endl;        	
        	}
        }
        */
        
        
    }
    return 0;
}


