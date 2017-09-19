#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;

struct TNode{
    int count;
    char letter;
    map<char,TNode*> next;
}*root;

int insert(TNode * cur,string s,int pos)
{
    if(pos==s.length())
    {
    
    if(cur->next.find('0')==cur->next.end()){
    TNode *end=new TNode();
    end->letter='0';
    end->count=1;
    cur->next['0']=end;
    
    return cur->next.size()==1?1:0;
    }
    return 0;
    }
    if(cur->next.find('0')!=cur->next.end())
    {
    return 0;
    }
    if(cur->next.find(s[pos])==cur->next.end())
    {
        TNode * add = new TNode();
        add->count=1;
        cur->next[s[pos]]=add;
    }
    else{
	cur->next[s[pos]]->count++;
    }
    return insert(cur->next.find(s[pos])->second,s,pos+1);
}

int find(TNode * cur,string s,int pos)
{
if(pos==s.length())return cur->count;
    if(cur->next.find(s[pos])==cur->next.end())
    {
        return 0;
    }
    return find(cur->next.find(s[pos])->second,s,pos+1);
}

void eliminateDuplicates() {
root=new TNode();
int n;cin>>n;
int flag;
    while(n--)
    {
        string str;
        cin>>str;
       // cout<<insert(root,str,0)<<"  "<<str<<endl;
        flag=insert(root,str,0);
        if(flag){
        continue;
        }
        cout<<"BAD SET\n"<<str<<endl;
        return;
        
   }
   cout<<"GOOD SET\n";
}
int main()
{
eliminateDuplicates();
}


