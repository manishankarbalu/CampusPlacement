/*Program to alternatively split a linked list into two halves */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
void AlternatingSplit(struct node* source, struct node** Oh, struct node** Eh) 
{
	if(!source) return;
	*Oh=source;
	if(source->next)
	*Eh=source->next;
	else
	*Eh=NULL;
	struct node *ep=(*Eh),*op=(*Oh);
	
	while(ep->next!=NULL || op->next!=NULL)
	{
		op->next=ep->next;
		if(ep->next)
		   op=ep->next;
		ep->next=op->next;
		 if(op->next)
		    ep=op->next;
	}
	if(ep!=NULL) ep->next=NULL;
	if(op!=NULL) op->next=NULL;
	
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
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
  while(node!=NULL)
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
  struct node* a = NULL;
  struct node* b = NULL;  
 
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 0->1->2->3->4->5 */
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);                                    
  push(&head, 0);  
 
  printf("\n Original linked List:  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  AlternatingSplit(head, &a, &b); 
 
  printf("\n Resultant Linked List 'a' ");
  printList(a);            
 
  printf("\n Resultant Linked List 'b' ");
  printList(b);            
 
  getchar();
  return 0;
}