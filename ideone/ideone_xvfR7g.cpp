
 #include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to swap nodes x and y in linked list by
   changing links */
void swapLinks(struct node* &head, int val1, int val2)
{
      if(!head)
      	 return;
      struct node *xptr=NULL,*yptr=NULL,*x=NULL,*y=NULL,*ptr=head;
  cout<<"entered";
      while(ptr->next)
      {cout<<"inside  ";
      	if(ptr->next->data==val1)
      	{
           xptr=ptr;
      	}
      	if(ptr->next->data==val2)
      	{
      		yptr=ptr;
      	}
      	ptr=ptr->next;
      }
      cout<<xptr->data<<"\t"<<yptr->data;
    if(xptr && yptr)
    {
      x=xptr->next;
      y=yptr->next;
       ptr=y->next;
    
    xptr->next=y;
    yptr->next=x;
    y->next=x->next;
    x->next=ptr;
    }
    else
    {
    	return;
    }
   if(head==x)
       head=y;
    else
      if(head==y)
         head=x;
      
    
}

/* Function to add a node at the begining of List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 
    swapLinks(start, 1, 2);
 
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
 
    return 0;
}