#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
void RemoveLoop(struct node *head,struct node *loop)
{
   while(head!=loop->next)
   {
   	head=head->next;
   	loop=loop->next;
   }
   loop->next=NULL;
}
void detectAndRemoveLoop(struct node* head)
{
	if(!head) return;
	
	struct node *fptr=head->next,*sptr=head;
	
	while(sptr && fptr && fptr->next)
	{ if(sptr==fptr)
	       {
	       	 RemoveLoop(head,sptr);
	       	return;} 
	    sptr=sptr->next;
	    fptr=fptr->next->next;
	      
	}
	
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
struct node *newNode(int key)
{
    struct node *temp = new struct node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
/* Drier program to test above function*/
int main()
{
    struct node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}