#include<stdio.h>
#include<stdlib.h>
struct listnode
{
int val;
struct listnode * next;
};

listnode* listnode_new(int val) {
      listnode* node = (listnode *) malloc(sizeof(listnode));
      node->val = val;
      node->next = NULL;
      return node;
  }
listnode * addlistnode(listnode *head,int val)
{
listnode *toadd=head;
if(head==NULL)
	{
	head=listnode_new(val);
	}
else
	{
	while(toadd->next)
		{
		toadd=toadd->next;
		}
	listnode * n1=listnode_new(val);
	toadd->next=n1;
	}
return head;
}
void printList(listnode *head)
{
listnode * cp=head;
	while(cp)
	{
	printf("%d\n",cp->val);
	cp=cp->next;
	}
}

int size(listnode *A)
{
int s=0;
listnode *cp=A;
while(cp)
	{
	s+=1;
	cp=cp->next;
	}
return s;
}

listnode* mergeTwoLists(listnode* A, listnode* B) {
    
     listnode *head,*ap,*bp,*cp,*add;
    ap=A;bp=B;
    if(A==NULL)return B;
    if(B==NULL)return A;
    
    else
    {
        if(ap->val>bp->val)
        {
          head=bp;
          cp=head;
          bp=bp->next;  
        }
        else
        {
            
        head=ap;
        cp=head;
        ap=ap->next;  
        
        }
        while(ap&&bp)
        {
        if(ap->val>bp->val)
        {
         add=listnode_new((bp->val));
          cp->next=add;
          bp=bp->next;  
        }
        else
        {
            
          add=listnode_new(ap->val);
          cp->next=add;
          ap=ap->next;  
        
        }
        }
         while(ap)
        {
          add=listnode_new(bp->val);
          cp->next=add;
          bp=bp->next;  
        }
        while(bp)
        {
          add=listnode_new(ap->val);
          cp->next=add;
          ap=ap->next;
        }
        return head;
        
    }
}
int main()
{
listnode *head1,*head2;

for(int i=1;i<=10;i++)
head1=addlistnode(head1,i*2);

for(int i=1;i<=10;i++)
head2=addlistnode(head2,i*2+1);

printList(head1);
printf("\n\n\n\n");
/*
//printList(head);
//printf("\n\n");
int k=5;
*/
/*
head=reverse(head,Kthlistnode(head,k));
for(int i=1;i<l/k;i++)
{
reverse(temp,Kthlistnode(temp,k));
}
printList(head);
*/
//printList(head);

//printList(reverse(Kthlistnode(head,5),Kthlistnode(head,10)));
//printList(reverse(head,end));
//printf("\n%d",reverse(head)->val);//) printf("NOT");
/*printList(head1);
printList(head);
*/
}

