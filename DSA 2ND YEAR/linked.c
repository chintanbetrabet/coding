#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node * next;
	int data;
	}*head1,*head2,*temp,*h;
void add(int v)
{ 
	temp=(struct Node*)malloc(sizeof(temp));
	temp->data=v;
	temp->next=NULL;
	if(head1==NULL){
		head1=temp;
		}
		else {
			temp->next=head1;
			head1=temp;
			}
}
Node* MergeLists(Node *headA, Node* headB)
{
  Node *h1=headA,*h2=headB;
    Node* tail=NULL;h=NULL;
    while(h1&&h2)
        {
        if(h1->data<h2->data)
            {
            if(h==NULL)
            {
                h=h1;
                tail=h1;
            }
            else {
                tail->next=h1;
                tail=h1;
            }
            h1=h1->next;
        }
        else
            {
            
            if(tail==NULL){
                h=h2;
                tail=h2;
            }
            else {
                tail->next=h2;
                tail=h2;
            }
            h2=h2->next;
        
        }
    }
    while (h1)
        {
        tail->next=h1;
                tail=h1;
    }
    while(h2)
        {
        tail->next=h2;
                tail=h2;
    }
    return h;
}
Node* Delete(Node *head, int position)
{
   int pos=0;
    if(position==0)
        {
        struct Node* temp=head;
        head=head->next;
        delete(temp);
    }
    else {
	   // printf("ELSE");
        struct Node* curr=head;
        while(pos<position-1)
            {
	           // printf("ELSE");
            pos++;
            curr=curr->next;
        }
        
        struct Node* temp=curr->next;
        curr->next=curr->next->next;
        delete(temp);
    }
    return head;
  // Complete this method
}
 struct Node* Reverse(Node *head1)
{
   struct Node * t=head1;
   struct  Node * nHead=head1;
   nHead->next=NULL;
   // nHead=head;
   while(t!=NULL)
        {
       struct Node *temp=(struct Node *)malloc(sizeof(temp));
	temp->data=t->data;
	temp->next=nHead;
        nHead=temp;
       t=t->next;
    }
  return nHead;
}
void show()
{
	Node* s=head1;
	while(s!=NULL){
	printf("%d ",s->data);
	s=s->next;
	}
}
Node* RemoveDuplicates(Node *head)
{
    Node *c=head;
    
    while(c!=NULL)
        {
        int val=c->data;
        //c=c->next;
        Node *t=c->next;
        while(t&&t->data==val)
            {
	            //printf("del:%d",val);
            Node *d=t;
            t=t->next;
            //c=c->next;
            delete(d);
        }
        c->next=t;
        c=c->next;
       
        
        
    }
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    return head;
}

int main()
{
	add(1);add(1);add(1);add(1);add(1);add(1);add(2);add(2);add(2);add(2);add(2);add(3);add(3);add(3);add(3);add(3);add(3);add(3);add(3);
RemoveDuplicates(head1);
	show();
	//printf("JJ");
}