#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node
    {
    int v;
    Node *next;
}*head,*tail;
void add(int val)
    {
    Node * x=new Node();
    x->v=val;
    x->next=NULL;
    if(head==NULL)
        {
        head=x;tail=x;
    }
    else{
        tail->next=x;tail=x;
    }
}
void insert(int val)
    {
    Node * temp=head;
    if(head==NULL)
    {
	    head=new Node();
	    head->v=val;
	    head->next=NULL;
	  }
    else {while(temp&&temp->next&&temp->next->v<val)
        {
        temp=temp->next;
    }
    Node * x=new Node();
    x->v=val;
    x->next=temp->next;
    temp->next=x;  
    }  
}
int pop()
    {
    if(head==NULL)return -1;
    int v1=head->v;
    head=head->next;
    return v1;
}
void show()
{
	Node * st=head;
	while(st!=NULL)
	{
	printf("%d ",st->v);
	st=st->next;
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,i,k,allow=1;;
    cin>>n>>k;
    for(i=0;i<n;i++)
        {
        int t;
        cin>>t;
        if(t>k){
            if(allow==1)
            add(t);
            else allow=0;
               }
        else add(t);       
    }
    int count=0;
   while(head&&head->v<k)
        {
        //printf("TAKING:%d\n",head->v);
        count++;
        //show();
        int min=pop();
        //show();printf("\n");
        int min2=pop();
        //printf(" %d %d \n",min,min2);
        if(min2>-1&&min>-1)
        insert(min+2*min2);
        if(min==-1||min2==-1) {
           count=-1;
       }
    }
    //insert(7);
    //show();
    printf("\n%d",count);
    return 0;
}
