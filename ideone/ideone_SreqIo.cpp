// C++ program to reverse a linked list using two pointers.
#include<bits/stdc++.h>
using namespace std;

 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
void reverseUtil(struct node* cur,struct node* pre,struct node** head,int *i)
{
	struct node *next=cur->next;
	if(cur->next==NULL && (*i)==3)
	{
		*head=cur; 
		cur->next=pre;
		return;
	}
	cur->next=pre;
	(*i)++;
	reverseUtil(next,cur,head,i);
	
}
 
/* Function to reverse the linked list using 2 pointers */
void reverse(struct node** head)
{
      if(*head==NULL) return;int i=0;
      reverseUtil(*head,NULL,head,&i);
}
 
/* Function to push a node */
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
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
 push(&head, 35);
 push(&head, 45);
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list \n");
    printList(head);
    return 0;
}