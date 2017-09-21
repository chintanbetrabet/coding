#include<iostream>
  #include<vector>
  
  using namespace std;
  int ev=-1;
  int collisions=0;
  int hash_s(int x,int s,int s1,int i)
 {
	 int hv=((12*x+11)%s+i*i+i)%s;
	 int h1=(x%10+i)%10;
  return h1;
 }
 int hash(int k,int a,int b,int m,int i)
 {
	int h= ((a*k+b)%m+i)%m;
	return h;
}	
void insertH(int table[],int v,int a,int b,int m)
{
    if(table[(hash(v,a,b,m,0))]==ev)
    {
    table[(hash(v,a,b,m,0))]=v;
    cout<<"\nINSERTEd "<<v<<" AT "<<(hash(v,a,b,m,0));getch();
    }
    else
    {
    
    int i=1;
    cout<<"\nCOllISION ON KEY :"<<v<<" AT index "<<(hash(v,a,b,m,0));
        while(table[(hash(v,a,b,m,i))]!=ev){
	     cout<<"\nCOllISION ON KEY :"<<v<<" AT index "<<(hash(v,a,b,m,i));
        i++;
        }
        collisions+=i;
        
        table[(hash(v,a,b,m,i))]=v;
            cout<<"\nINSERTEd "<<v<<" AT "<<(hash(v,a,b,m,i));getch();
    }
}
/*
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
}*/
 int main()
{
	int n;
 //cin>>n;
 n=10;
 const int s=13;
//const int s1=31;
 int ar[s]={},ar2[s]={},ar3[s]={},val[s]={};
//cout<<n<<endl;
 for(int i=0;i<s;i++)
 ar2[i]=ev;
 for(int i=1;i<=n;i++)
 {
 val[i]=(383*i)%83;
 }
 //cout<<val[0]<<endl;
 /*for(int i=0;i<n;i++)
 {
     insertHL(ar,val[i],s,s1);
 }
 cout<<"COLLISIONS: "<<collisions<<endl;
 collisions=0;*/
  for(int i=1;i<=n;i++)
 {
     insertH(ar2,val[i],8191,683,13);
     
     
 }
  cout<<"COLLISIONS: "<<collisions<<endl;
   collisions=0;
 /* for(int i=0;i<n;i++)
 {
     insertDH(ar3,val[i],s,s1);
 }
  cout<<"COLLISIONS: "<<collisions<<endl;
   collisions=0;
cout<<endl;*/

/*
 for(int i=0;i<s;i++)
 {
 cout<<ar[i]<<endl;
 }
 cout<<endl;
 */
 for(int i=0;i<s;i++)
 {
	 if(ar2[i]!=ev)
 cout<<ar2[i]<<endl;
 else cout<<'X'<<endl;
 }
 cout<<endl;
 /*for(int i=0;i<s;i++)
 {
 cout<<ar3[i]<<endl;
 }*/
}
 