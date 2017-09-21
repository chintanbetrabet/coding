#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
int const size=10000;
using namespace std;
struct Node{
    char *str;
    Node*next;
}*head;
Node * initNode(char *s)
    {
    Node * add;
    add->str=(char *)malloc(strlen(s)+1);
    strcpy(add->str,s);
    return add;
    }
void push(char *s)
    {
    Node *add=initNode(s);
    int len=strlen(s);
    char str1[len];
    strcpy(str1,s);
   strcpy(add->str,str1);
    add->next=NULL;
    
    if(head!=NULL){
    add->next=head;
    head=add;
    }
    else head=add;
}
void popTo(char *s)
    {
     strcpy(s,head->str);
    Node * temp=head;
    head=head->next;
    delete(temp);
}


int main() {
    char str[size];
    int undo=0;
    str[0]='\0';
    //push(str);
    int n;
    cin>>n;
        for(int i=0;i<n;i++)
        {
           // cout<<"\ni="<<i;

        int op;
        cin>>op;
        //cout<<"op="<<op<<"\n";
        switch(op)
            {
            case 1:{
                char str2[size];
                cin>>str2;
                char strtemp[strlen(str)];
                strcpy(strtemp,str);
                push(strtemp);
                strcat(str,str2);  
                //cout<<str<<"\n";
                
            }break;
            case 2:{
                //cout<<"2";
                int len=strlen(str);
                 char strtemp[strlen(str)];
                strcpy(strtemp,str);
                push(strtemp);
                int k;cin>>k;
                //if(k<len)
                   // {
                    //cout<<" setting "<<len-k<<" as null";
                    str[len-k]='\0';
               // }
                undo=1;
                //if(strlen(str)==0)cout<<"NULL\n";
                //else cout<<str<<endl;
                
            }break;
            case 3:{
                
                int k;
                cin>>k;
                char c=str[k-1];
                cout<<c<<"\n";
               //cout<<str[k];
                
            }break;
            case 4:{
                popTo(str); 
                //cout<<str<<"\n";
                
            }break;
        }
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}