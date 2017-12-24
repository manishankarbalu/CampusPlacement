// C program to delete nodes which have a greater value on 
// right side
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
 
/* structure of a linked list node */
struct node
{
     int data;
     struct node *next;
};
 
//Delete all greater nodes in right side

void reverseList(struct node* &head)
{
	if(!head)
		return;
	
	struct node* first=head;
	struct node* rest=head->next;
    if(!rest)
    	return;

    reverseList(rest);

    first->next->next=first;
    first->next=NULL;
    head=rest;
}

void deleteGreaterRightNodes(struct node* &head)
{
	
	reverseList(head);
    struct node* slow=head,*fast=head->next;
    while(fast)
    {
    	if(fast->data<slow->data)
    	{
    		slow->next=fast->next;
    		delete(fast);
    		fast=slow->next;
    	}
    	else
    	{
    		slow=slow->next;
    		fast=slow->next;
    	}
    }
    reverseList(head);
}
 
/* Utility function to insert a node at the begining */
void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}
 

/* Utility function to print a linked list */
void printList(struct node *head)
{
     while (head != NULL)
     {
        printf("%d ", head->data);
        head=head->next;
     }
     printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    struct node *head = NULL;
 
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    printf("Given Linked List \n");
    printList(head);
 
    deleteGreaterRightNodes(head);
 
    printf("Modified Linked List \n");
    printList(head);
 
     return 0;
}