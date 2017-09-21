#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    cin>>n;
    string s;
    int ar[26]={};
    cin>>s;
    
    for(int i=0;i<n;i++)
        {
        ar[s[i]-'a']++;
    }
    int hi=n,lo=0;
    //while(hi>lo)
       // {
        int mid=(hi+lo)/2;
        int left[26]=ar;
        for(int i=0;i<n-mid;i++)
            {
            cout<<s.substr(i,mid)<<endl;
        }
    //}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
