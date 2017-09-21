#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>

#include <vector>
#include <cstdlib>
#include <numeric>

#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void median(vector<char> s,vector<int> X) {
    vector<int> v;int size=0;
    int exist[100001]={};
   for(int i=0;i<s.size();i++)
       {
       if(s[i]=='a')
           {
           v.push_back(X[i]);
           sort(v.begin(),v.end());
           size++;
           exist[X[i]]=1;
           if(size%2==1)
               cout<<v[size/2]<<"\n";
            else if((v[size/2]+v[size/2-1])%2==0)
                           cout<<(v[size/2]+v[size/2-1])/2;
                       else {
                           cout<<(float(v[size/2])+float(v[size/2-1]))/2;
                       }
       }
       else{
           if(size==0||exist[X[i]]==0)
               cout<<"Wrong!\n";
           else{
               v.erase(std::remove(v.begin(), v.end(), X[i]), v.end());
               sort(v.begin(),v.end());
               size--;
               exist[X[i]]=0;
               if(size==0)
                   cout<<"Wrong!\n";
               else{
                   if(size%2==1)
                       cout<<v[size/2]<<"\n";
                   else{    
                       if((v[size/2]+v[size/2-1])%2==0)
                           cout<<(v[size/2]+v[size/2-1])/2;
                       else {
                           cout<<(float(v[size/2])+float(v[size/2-1]))/2;
                       }
}
                       
               }
           }
       }
   }
    
}
int main(void){

//Helpers for input and output

   int N;
   cin >> N;
   vector<int> v;
   v.push_back(2);
   v.push_back(2);
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
    cout<<v.size();
   /*vector<char> s;
    vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   
   median(s,X);*/
   return 0;
}
