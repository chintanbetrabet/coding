#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct tree{
	int data;
	int count;
	tree * leftChild,*rightChild,*parent;
	}*root;
struct tree * getPredeccessor(struct tree* a);
struct tree * getSuccessor(struct tree* a);
struct tree * getLeafSuccessor(struct tree* a);
struct tree * getLeafPredeccessor(struct tree* a);
struct tree *getMin();
struct tree *getMax();
struct tree *gp1(tree* node);

struct tree* create(int val,struct tree*parent=NULL)
{
struct tree *ret;
	ret=malloc(sizeof(tree));
	ret->data=val;ret->count=1;
	ret->parent=parent;
	ret->leftChild=NULL;
	ret->rightChild=NULL;
	return ret;
}
void add(int val,struct tree* curr)
{
	if(curr->data>val)
	{
		if(curr->leftChild)
		add(val,curr->leftChild);
		else {
			curr->leftChild=create(val,curr);
			}
	}
	else if(curr->data<val)
	{
		if(curr->rightChild)
		add(val,curr->rightChild);
		else {
			curr->rightChild=create(val,curr);
			}
		
	}
	else curr->count++;
}
void addToTree(int val)
{
	if(root==NULL)
	{
		root=create(val);
	}
	else{
		tree *curr=root;
		add(val,curr);
		}
}

int isLeaf(tree *node)
{
	if(node->leftChild||node->rightChild)
	{
		return 0;
	}
	return 1;
}
int isFull(tree *node)
{
	if((node->leftChild&&node->rightChild))
	return 1;
	return 0;
}
int isLeft(tree* node)
{
	if(node->parent&&node->parent->data>node->data)
	return 1;
	return 0;
}
tree * gp1(struct tree* curr)
{
	struct tree *node=curr;
	if(node==getMin())
	printf("MIN");
	else if(isLeft(node))
	{
		if(node->leftChild)
		{
			node=node->leftChild;
			while(node->rightChild)
			{
				node=node->rightChild;
			}
			return node;
		}
		else {
				if(node->parent)
				{
					node=node->parent;
					while(isLeft(node)==0)
					node=node->parent;
					return node;
				}
			}
	}
	else {
		if(node->leftChild)
		{
			node=node->leftChild;
			while(node->rightChild)
			{
				node=node->rightChild;
			}
			return node;
		}
		else {
				if(node->parent)
				{
					node=node->parent;
					while(isLeft(node)==0&&node->parent&&node->leftChild)
					node=node->parent;
					return node;
				}
				printf("MIN");
				return NULL;
			}
		
		}
		return NULL;
}
struct tree* gs1(tree* curr)
{
	struct tree *node=curr;
	if(node==getMax())
	return NULL;
	else if(isLeft(node))
	{
		if(node->rightChild)
		{
			node=node->rightChild;
			while(node->leftChild)
			{
				node=node->leftChild;
			}
			return node;
		}
		else {
				if(node->parent)
				{
					node=node->parent;
				/*	while(isLeft(node)==0&&node->rightChild)
					node=node->parent;*/
					return node;
				}
			}
	}
	else {
		if(node->rightChild)
		{
			node=node->rightChild;
			while(node->leftChild)
			{
				node=node->leftChild;
			}
			return node;
		}
		else {
				if(node->parent)
				{
				node=node->parent;
				if(isLeft(node))
				node=node->parent;
					return node;
				}
		return NULL;
			}
		
		}
		return NULL;
	
}
struct tree* getLeafPredecessor(tree* node)
{
	printf("LEAF");
	if(node==getMin())
	printf ("MIN");
else	if(node->parent)
	{		
		if(isLeft(node)==0)
		{
			node=node->parent;
			while(isLeft(node))
			{
			if(node->parent)				
			node=node->parent;
			else break;
			}
			return node;
		}
		else if(node!=root){
			node=node->parent;
			while(isLeft(node)==1)
			{
			if(node->parent)				
			node=node->parent;
			else break;
			}
			return node;
			}
	}
	return NULL;
}
tree * getPredecessor(struct tree* node)
{
	return gp1(node);
}
struct tree* getSuccessor(struct tree* node)
{printf("called Suc");
	if(node->rightChild)
	{
		node=node->rightChild;
		while(node->leftChild)
		node=node->leftChild;
	}
	printf("returning: %c ",node->data);
	return node;
}
int del(int val,tree*curr)
{
			//printf("1.YO");

if(curr->data>val)
	{
	//printf("\nGo left");
		if(curr->leftChild)
		return del(val,curr->leftChild);
		else {
			return -1;
			}
	}
	else if(curr->data<val)
	{
	//	printf("\nGo right");
		if(curr->rightChild)
		return del(val,curr->rightChild);
		else {
			return -1;
			}
		
	}
	else {
		
			if(isLeaf(curr)==1)
		{
			if(curr->count>1)
			curr->count--;
//printf("\nStop at %c",curr->data);
		else if(curr==root)
			{
	//printf("\nfound root=%c,%c\n",root->data,curr->data);	
	root=NULL;	
			}
			else if(curr->parent&&curr->parent->data>curr->data)
			{
				curr->parent->leftChild=NULL;
			}
		else	if(curr->parent&&curr->parent->data<curr->data)
			{
				curr->parent->rightChild=NULL;
			}
			curr=NULL;
		}
			else {//printf("\nfound\n");
			  if(curr->count>1)
			  {
				  printf("dup");
			  curr->count--;     
			  }                                                                                                                                                                                                           
				
		    else if(!isFull(curr))
				{
				if(isLeft(curr)&&curr->leftChild)
					{
					if(curr->parent){
					curr->parent->leftChild=curr->leftChild;
					curr->leftChild->parent=curr->parent;
					}
					else 
					{
						curr->leftChild->parent=NULL;
						root=curr->leftChild;
					}	
				
					
				}
				if(isLeft(curr)&&curr->rightChild)
					{
				
					if(curr->parent)
					{
					curr->parent->leftChild=curr->rightChild;
					curr->rightChild->parent=curr->parent;
					}
					else {
						curr->rightChild->parent=NULL;
						root=curr->rightChild;
						}
				}
				if(!isLeft(curr)&&curr->leftChild)
					{	
					if(curr->parent)
						{
					curr->parent->rightChild=curr->leftChild;
					curr->leftChild->parent=curr->parent;
						}
						else {
							curr->leftChild->parent=NULL;
							root=curr->leftChild;
							}
					}
				if(!isLeft(curr)&&curr->rightChild)
					{	
					if(curr->parent){
					curr->parent->rightChild=curr->rightChild;
					curr->rightChild->parent=curr->parent;
					}
					else {
					curr->rightChild->parent=NULL;
					root=curr->rightChild;
						}
				}
				curr=NULL;
				
				}
				else {
					//printf("found");
					tree*pred;
					pred=getPredecessor(curr);
					int c,d;
					if(pred){
						d=pred->data;
					c=pred->count;
					
					}
					else {pred=gs1(curr);
					d=pred->data;
					c=pred->count;
					}
						
					del(pred->data,curr);
					curr->data=d;
					curr->count=c;
					}
					
			}
	}
	return 1;
}
void showSorted()
{
	tree *start=getMin();
	//start=gs1(start);
	int mval=getMax()->data;
	//printf("max=%c next=%c",mval,start->data);
	
	while(1==1)
	{
		printf("%c ",start->data);
		if(start->data==mval)break;
		start=gs1(start);
		
		//getch();
	}
}
void show(tree* curr=root)
{
	if(curr!=NULL)
	{
		printf(" \nDATA= %c COUNT=%d ",curr->data,curr->count);
		if(curr->leftChild)
		printf(" left=%c",curr->leftChild->data);
		if(curr->rightChild)
		printf(" right=%c",curr->rightChild->data);
		if(curr->parent)
		printf(" parent=%c",curr->parent->data);
		tree *pre;
		pre=getPredecessor(curr);
		tree *post=gs1(curr);
		if(pre)
		printf(" Pred= %c ",pre->data);
		if(post)
		{
			printf(" Succ= %c ",post->data);
		}
		show(curr->leftChild);
		show(curr->rightChild);	
	}
}
tree * getMin()
{
	struct  tree *node=root;
	while(node->leftChild)
	{
		node=node->leftChild;
	}
	return node;
}
tree * getMax()
{
	struct  tree *node=root;
	while(node->rightChild)
	{
		node=node->rightChild;
	}
	return node;
}
tree * get(int key,tree *source)
{
	if(key==source->data)
	return source;
	else if(key>source->data)
	{
		if(source->rightChild)
		return get(key,source->rightChild);
		else return NULL;
	}
	else if(source->leftChild)
		return get(key,source->leftChild);
		else return NULL;
}
int main()
{
	//tree *T;
	char str[100],str2[100];
scanf("%s",str);
int i=0;
while(str[i]>0)
{
	addToTree(str[i]);i++;
}
i=0;
while(str[i]!='\0'&&str[i]==getMax()->data)
{
	str2[i]=str[i];// getch();
	del(str[i],root);
	i++;
}

while(str[i]!='\0'&&str[i]!=getMin()->data)
{
	str2[i]=str[i];
	del(str[i],root);
	i++;
}
/*
del('e',root);
del('c',root);
printf("ROOT=%c",root->data);
show();*/
int size=i;
if(str[i]!='\0'){

tree *curr =getMin();
tree *temp=gs1(curr);
	printf("POPO :%c",curr->data);
str2[size]=temp->data;size++;

del(temp->data,root);

while(curr)
{
str2[size]=curr->data;size++;
	curr=gs1(curr);
}
str2[i]='\0';
printf("%s",str2);
}
else printf("no answer");
	//showSorted();
//	printf("\nSuccess");
}
