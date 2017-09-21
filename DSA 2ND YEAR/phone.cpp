#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<string.h>
using namespace std;


int main() {
    
    char s[100];
    map<char*,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        {
         int v;
        
        cin>>s>>v;
    	cout<<strcmp("sam",s);
        m.insert(pair<char*,int>(s,v));
    }
   
   char old[100]=" ",newS[100]="1";
   cin>>old;
   
    while(strcmp(old,newS)!=0)
        {
       // cout<<old<<endl;
       cout<<strcmp("sam",old);
        if(m.find("sam")!=m.end())
            {
            cout<<old<<"="<<(*(m.find("sam"))).second<<endl;
            }
        else if(old!="2")cout<<"Not found\n";
        strcpy(newS,old);
        cin>>old;
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
