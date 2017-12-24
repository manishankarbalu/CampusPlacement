// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
 
void segregateEvenOdd(struct node **head)
{
    if(!(*head))
        return;
   struct node * cur=*head;
   struct node *Eh=NULL,*ep=NULL,*Oh=NULL,*op=NULL;int i=0,j=0;

   while(cur)
   {
   	  if(cur->data%2)
   	  {
   	  	if(j==0)
   	  	{
   	  		Oh=cur;
   	  		op=Oh;j++;
   	  	}
   	  	else
   	  	{
   	  	    op->next=cur;
   	  	    op=op->next;
   	  	}
   	  }
   	  else
   	  {
   	  	if(i==0)
   	  	{
   	  		Eh=cur;
   	  		ep=Eh;i++;
   	  	}
   	  	else
   	  	{
   	  	    ep->next=cur;
   	  	    ep=ep->next;
   	  	}
   	  }
   cur=cur->next;
   }
   *head=Eh;
   ep->next=Oh;
   op->next=NULL;
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning  */
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
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 7);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    segregateEvenOdd(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}