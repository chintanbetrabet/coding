#include<iostream>
#include<algorithm>
#include<vector>
#include<conio.h>
using namespace std;

struct node{
	node * p;
	node * l;
	node * r;
	int key;
	char color;
	
	}*root;
	void All(node * x);
node* Node (node * pa,int k)
{
	node *n = new node();
	n->p=pa;
	n->l=NULL;
	n->r=NULL;
	n->color='r';
	n->key=k;
	return n;
}
void Lr(node * x)
{
	cout<<"\n called LR on "<<x->key;
	node * y=x->r;
	x->r=y->l;
	if(y->l)
	{
		y->l->p=x;
	}
	y->p=x->p;
	if(!x->p)
	{
		//cout<<"SET ROOT TO "<<y->key;
		root=y;
	}
	else if(x==x->p->l)
	{
		x->p->l=y;
	}
	else 
	{
		x->p->r=y;
	}
	y->l=x;
	x->p=y;
}
void Rr(node * y)
{
		cout<<"\n called RR on "<<y->key;
	node *x=y->l;
	y->l=x->r;
	if(x->r)
	{
		x->r->p=y;
	}
	x->p=y->p;
	if(y->p==NULL)
	{
		root=x;
	}
	else if(y==y->p->l)
	{
		y->p->l=x;
	}
	else
	{
		y->p->r=x;
	}
	x->r=y;
	y->p=x;
	
	
	
}
void fix(node * x)
{
	cout<<"\nfix:"<<x->key;
	node *z=x;
	node *y;
	
	while(z->p && z->p->color=='r')
	{
		cout<<"\nSTuck in "<<z->key;
		if(z->p==z->p->p->l)
		{
		//	cout<<"\n"<<z->key<<" is a left\n";
			y=z->p->p->r;
			if(y->color=='r')
			{
			//	cout<<"RED uncle case\n";
			//	cout<<"Z = "<<z->key<<" Y is "<<y->key;
				z->p->color='b';
				y->color='b';
				z->p->p->color='r';
				z=z->p->p;
			}
			else if(z==z->p->r)
			{
				cout<<"\nROTS";getch();
			/*	z=z->p;
				Lr(z);
				z->p->color='b';
				z->p->p->color='r';
				Rr(z->p->p);*/
			}
		}
		
		else
			{
			cout<<"\n "<<z->key<<" is a right oof color "<<z->color<<"\n";
			y=z->p->p->l;
			
			if(!y)
			cout<<"\nNULL UNCLE";
			if(y&&y->color=='r')
			{
			//	cout<<"RED uncle case\n";
				z->p->color='b';
				y->color='b';
				z->p->p->color='r';
				z=z->p->p;
			}
			else if(z==z->p->r)
			{
				cout<<"ROTS";getch();
			//	z=z->p;
				
				Lr(z->p->p);
				cout<<"\nHIL ";
					z->p->color='b';
					z->p->l->color='r';
				z->p->p->color='r';
			//	Rr(z->p->p);
				cout<<"\nHIR\n Root="<<root->key<<endl;
					root->color='b';
				All(root);
				getch();
				z=z->p->p;
			
			}
			
			
							
			}
		//	All(root);
		
	}
}
void Rbins(int v)
{
//	cout<<"ASED FOR "<<v;
	if(root==NULL)
	{
		root=Node(NULL,v);
		root->color='b';
		return;
	}
	node *y=NULL;
	node* x=root;
	
	while(x)
	{
	//cout<<" HI during "<<v;
		y=x;
		if(v<x->key)
			{
				x=x->l;
			}
			else x=x->r;
	}
	node *z=Node(y,v);
	if(y==NULL)
	{
		root=z;
	}
	else if(z->key>y->key)
	{
		
		y->r=z;
	}
	else y->l=z;
//	cout<<"\n STart fix for "<<v;
	fix(z);
	cout<<"\n end fix for "<<v;
//	cout<<"\nX is "<<y->l->key;
	root->color='b';
	//cout<<" Root is "<<root->color;
}
void All(node * x)
{
	if(x->l)
	{
		All(x->l);
	}
	cout<<"V= "<<x->key<<" color ="<<x->color;//<<endl;
	if(x->l)
	cout<<"  l="<<x->l->key<<" ";
	if(x->r)
	cout<<"  r="<<x->r->key<<" ";
	cout<<endl;
		if(x->r)
	{
		All(x->r);
	}
	
}
int main()
{
	//int ar[]={2,3,1,4,5};
//	int l=4;
	/*for(int i=0;i<sizeof(ar)/2;i++)
	{
		Rbins(ar[i]);	
		cout<<"\nROOT = "<<root->key<<endl;
		All(root);
	cout<<endl;
		
	}*/
	root=Node(NULL,2);
	root->color='b';
	root->l=Node(root,1);
	root->l->color='b';	
	root->r=Node(root,3);
	root->r->color='b';
	root->r->r=Node(root,4);
	Lr(root);
	cout<<endl;
	All(root);

	//cout<<root->key<<endl;
	
}