#include<iostream>
  #include<vector>
  using namespace std;
  int collisions=0;
  int hash(int x,int s)
 {
  return x%s;
 }
  int qhash(int h,int i,int s)
 {
 return (hash(h,s)+i*i)%s;
 }
 int hash2(int x,int s1)
{
return x%s1;
}
void insertHL(int table[],int v,int s,int s1)
{
    if(table[(hash(v,s))%s]==0)
    {
    table[hash(v,s)]=v;
    }
    else
    {
    
    int i=1;
        while(table[(hash(v,s)+i)%s]!=0)
        i++;
        collisions+=i;
        table[hash(v,s)+i]=v;
    }
}
void insertHQ(int table[],int v,int s,int s1)
{
        if(table[hash(v,s)]==0)
    {
    table[hash(v,s)]=v;
    }
    else
    {
    int i=1;
        while(table[(qhash(v,i,s))]!=0)
        i++;
        collisions+=i;
        table[qhash(v,i,s)]=v;
    }
}
void insertDH(int table[],int v,int s,int s1)
{
        if(table[hash(v,s)]==0)
    {
    table[hash(v,s)]=v;
    }
    else
    {
    int i=1;
        while(table[(hash(v,s)+i*hash2(v,s1))%s]!=0)
        i++;
        collisions+=i;
        table[(hash(v,s)+i*hash2(v,s1))%s]=v;
    }
}
 int main()
{
 const int s=13;
const int s1=31;
 int ar[s]={},ar2[s]={},ar3[s]={},val[s]={};

 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
 cin>>val[i];
 }
 for(int i=0;i<n;i++)
 {
     insertHL(ar,val[i],s,s1);
 }
 cout<<"COLLISIONS: "<<collisions<<endl;
 collisions=0;
  for(int i=0;i<n;i++)
 {
     insertHQ(ar2,val[i],s,s1);
 }
  cout<<"COLLISIONS: "<<collisions<<endl;
   collisions=0;
  for(int i=0;i<n;i++)
 {
     insertDH(ar3,val[i],s,s1);
 }
  cout<<"COLLISIONS: "<<collisions<<endl;
   collisions=0;
cout<<endl;
/*
 for(int i=0;i<s;i++)
 {
 cout<<ar[i]<<endl;
 }
 cout<<endl;
 for(int i=0;i<s;i++)
 {
 cout<<ar2[i]<<endl;
 }
 cout<<endl;
 for(int i=0;i<s;i++)
 {
 cout<<ar3[i]<<endl;
 }*/
}
 