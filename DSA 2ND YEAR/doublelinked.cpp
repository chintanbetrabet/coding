#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct Node{
	int data;
	Node* next;
}*head,*tail;
void print()
{
	Node * temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
void push(int v)
{
	if(head==NULL)
	{
		head=new Node();
		head->data=v;
		head->next=NULL;
		tail=head;
	}
	else 
	{
		Node* add = new Node();
		add->data=v;
		add->next=NULL;
		tail->next=add;
		tail=add;
	}
}
void getNodes(int type,int i,int j,int size){
	int ind=1;
	Node * temp=head;
	Node * nodeI,*nodeJ,*i1;
	
	if(i==1)
	i1=head;
	while(temp)
	{
		if(ind==i)
		{
			nodeI=temp;
		//cout<<"I\n";
		}
		else if(ind==i-1)
		{
			i1=temp;
				//	cout<<"I-1\n";
		}
		if(ind==j)
		{
			nodeJ=temp;
				//	cout<<"J\n";
		
		}
		//if(ind>=i&&ind<=j)
		//cout<<temp->data<<" ";
		ind++;
		temp=temp->next;
	}
	//	cout<<"V+"<<nodeI->data<<"  "<<nodeJ->data;
	if(type==1&&i!=1)
	{
			//cout<<"i:"<<nodeI->data<<" j:"<<nodeJ->data<<" i1:"<<i1->data<<"\n";
		i1->next=nodeJ->next;//cout<<"tail"<<tail->data<<" \n";
		nodeJ->next=head;//cout<<"tail"<<tail->data<<" \n";
		head=nodeI;//cout<<"tail"<<tail->data<<" \n";
	}
	if(type==2&&j!=size)
	{
	//cout<<"i:"<<nodeI->data<<" j:"<<nodeJ->data<<" i1:"<<i1->data<<"\n";
		tail->next=nodeI;
		if(i1!=head)
		i1->next=nodeJ->next;
		else{
			head=nodeJ->next;
		}
		tail=nodeJ;
		tail->next=NULL;
		
	}

}


int main()
{
	int i,n,q;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		int v;
		cin>>v;
		push(v);
	}
	for(i=0;i<q;i++)
	{
		int type,ind1,ind2;
		cin>>type>>ind1>>ind2;
		getNodes(type,ind1,ind2,n);
	}
cout<<abs(head->data-tail->data)<<"\n";
print();
}