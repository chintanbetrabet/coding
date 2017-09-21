#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxd[100000],maxe=0;
class Node{
   private :
    int v;
 int height;
 vector <int> children;
 int child;
    public: 
    Node()
        {
        height=1000000000;
        child=0;
    }
    Node(int val)
        {
        height=1000000000;
        v=val;
        child=0;
    }
    int getchildV(int index)
        {
        return children[index];
    }
    int getH()
        {
        return height;
    }
    void setH(int h)
        {
        height=h;
    }
    void append(int val)
        {
        children.push_back(val);
        child++;
    }
    int retC()
        {
        return child;
    }
    void printChildren()
        {
        cout<<"\n"<<v<<":";
        for(int i=0;i<child;i++)
            {
            cout<<children[i]<<" ";
        }
        
    }
    void resetC()
        {
        child=0;
    }
    void setV(int val)
        {
        v=val;
    }
    
    
    
};
int visited[100000]={};
int min(int x,int y)
    {
    if(x>y)return y;
    else return x;
}
int maxh=0,minh=100000;
void dft(int p,Node tree[],int hp)
    {
	    //cout<<"\n "<<p;
   visited[p]=1;
    int h=min(tree[p].getH(),hp+1);
    //cout<<"h= "<<h;
    if(h>maxh){
        maxh=h;
        maxd[0]=p;maxe=0;
        }
        if(maxh==h)
        {
	        maxd[maxe]=p;maxe++;
	     }
    if(h<minh&&tree[p].retC()==1)
        minh=h;
    tree[p].setH(h);
    //cout<<"\nHeight of "<<p<<" is "<<h<<"IO  h1="<<tree[p].getH()<<" h2="<<hp+1;
    if(tree[p].retC()==0)return;
    else {
        int childs=tree[p].retC();
        //cout<<"\n"<<p;
        for(int i=0;i<childs;i++)
            {
            //cout<<tree[p].getchildV(i);
            if(visited[tree[p].getchildV(i)]==0){
	            visited[tree[p].getchildV(i)]=1;
            dft(tree[p].getchildV(i),tree,h);
            }
        }
    }
}

int main() {
    int n,r;
    cin>>n>>r;
    //cout<<"R="<<r<<endl;
    Node tree[n+1];
    for(int i=1;i<=n;i++)
    {
        tree[i].setV(i);
        tree[i].resetC();
    }
    int added[100000]={};
    
    added[r]=1;
        for(int i=1;i<=n-1;i++)
            {
            int p,c;
            cin>>p>>c;
            //if(added[p]==1&&c!=r){
	            //cout<<"edge:"<<p<<" to "<<c<<"\n";
	           // ed++;
            tree[p].append(c);
           // }
          //  else {
            tree[c].append(p);
             //cout<<"edge:"<<c<<" to "<<p<<"\n";
             //ed++;
            //}
            //added[p]=added[c]=1;
        }
    /* for(int i=1;i<=n;i++)
            {
            tree[i].printChildren();
        }*/
  dft(r,tree,0);
    
    int d;
    for(d=0;d<maxe;d++)
    {
	    dft(maxd[d],tree,0);
	 }
	cout<<maxh<<"\n";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
