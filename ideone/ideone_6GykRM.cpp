/* C Program to move last element to front in a given linked list */
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* We are using a double pointer head_ref here because we change
   head of the linked list inside this function.*/
void moveToFront(struct node **head)
{
	if(!(*head) || !((*head)->next))
	    return;
	
	struct node *l1=NULL;
	
	struct node *l2=*head;
	
	while(l2->next!=NULL)
	{
		l1=l2;
		l2=l2->next;
	}
	
	l1->next=NULL;
	
	l2->next=*head;
	
	*head=l2;
}
 
/* UTILITY FUNCTIONS */
/* Function to add a node at the begining of Linked List */
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
     1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before moving last to front\n");
    printList(start);
 
    moveToFront(&start);
 
    printf("\n Linked list after removing last to front\n");
    printList(start);
 
    return 0;
}