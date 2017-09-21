#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>

using namespace std;
unsigned int top=0;
vector< pair<int,int> > queue;
set<int> tree[1000000];
int visited[1000000];
void makeTree(int x)
    {
    if(x<=0)return ;
    if(x==1){
        tree[1].insert(0);return;
    }
    if(x==2)
        {
        tree[2].insert(1);
        tree[1].insert(0);return;        
    }
    if(x==3)
        {
        tree[3].insert(2);
        tree[2].insert(1);
        tree[1].insert(0);return;
    }
    tree[x].insert(x-1);
    
    for(int i=x-2;i>=sqrt(x);i--)
        {
        if(i>0&&x%i==0)
        {
            tree[x].insert(i);
            //if(tree[i].empty()==true)
            //makeTree(i);            
        }
    }
   // makeTree(x-1);
    
}
int bfs(pair<int,int> x,int h)
{
	
	visited[x.first]=1;
	//cout<<x.first<<" at "<<h<<"\n has:";
    if(x.first==0)return x.second;
    makeTree(x.first);
   for(std::set<int>::iterator it=tree[x.first].begin(); it!=tree[x.first].end(); ++it)
    {
	    
	    //cout<<*it<<" ";
	    if(!visited[*it]){
	    pair<int,int> temp;
	    temp.first=*it;
	    temp.second=x.second+1;
       queue.push_back(temp);  
       }      
    }
    //cout<<"\n";
  //cout<<queue[top]->data;
    if(top<queue.size())
  return bfs(queue[top++],h+1);
  return -1;
  
}
int isPrime(int n)
{
    int i;
    if(n==1)return 0;
    if(int(sqrt(n))*int(sqrt(n))==n)
        return int(sqrt(n));
    for(i=int(sqrt(n))+1;i<=n/2;i++)
        {
        //cout<<"\nit on "<<i;
        if(n%i==0)return i;
    }
    return n-1;
}
int getMoves(int n)
{
	//cout<<"\n Call on "<<n;
    if(n<4)return n;
    return 1+getMoves(isPrime(n));    
}

int main() {
	int x,t;
    cin>>t;
    for(int i=0;i<t;i++){
	cin>>x;
  for(int j=0;j<=x;j++)
  {
	  visited[j]=0;
	  tree[j].clear();
	  queue.clear();
	  top=0;
  }
  
  pair<int,int> temp;
  temp.first=x;
  temp.second=0;
  int h=bfs(temp,0);
 // cout<<"\nres="<<h;
 cout<<h;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    }
    return 0;
}
