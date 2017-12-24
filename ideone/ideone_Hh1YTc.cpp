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
 void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    //printf("\n");
}
/* Function to swap nodes x and y in linked list by
   changing links */

struct node* reverseListInGroup(struct node* head,int k)
{
	if(!head)
		return NULL;
	struct node *current=head,*prev=NULL,*next=NULL;
    int i=0;
    while(current && i<k)
    {
    	next=current->next;
    	current->next=prev;
    	prev=current;
    	current=next;
    	i++;
    }
    
    if(next)
    	head->next=reverseListInGroup(next,k);

    return prev;
}

struct node* AlternateRevKGroup(struct node* &head, int k)
{
	if(!head)
		return NULL;
	struct node *current=head,*prev=NULL,*next=NULL;
    int i=0;
    while(current && i<k)
    {
    	next=current->next;
    	current->next=prev;
    	prev=current;
    	current=next;
    	i++;
    }
     printf("%d \n",prev->data);
    if(head)
    	head->next=current;
    //printList(head);
    i=0;
    while(current && i<k-1)
    {
    	current=current->next;
    	i++;
    }
    if(current)
    	current->next=AlternateRevKGroup(current->next,k);
    // printf("%d \n",prev->data);
    
    //printf("%d \n",prev->data);
    return prev;
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
 

 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
     push(&start, 10);push(&start, 9);
     push(&start, 8);
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 
   start=AlternateRevKGroup(start,3);
 // reverseListInGroup(start,3);
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
 
    return 0;
}