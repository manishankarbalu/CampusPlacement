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
	struct node *ptr1=loop,*ptr2=loop->next;
	int count=1;
	while(ptr1!=ptr2)
	{
	//	ptr1=ptr1->next;
		ptr2=ptr2->next;
		count++;
	}
//	printf("count %d ",count);
ptr1=head;ptr2=head;int i=0;
while(i<count)
{
	ptr2=ptr2->next;
}
while(ptr1!=ptr2)
{
	ptr1=ptr1->next;
	ptr2=ptr2->next;
}
i=0;
while(i<count-1)
{
	ptr2=ptr2->next;
}
ptr2->next=NULL;

}
void detectAndRemoveLoop(struct node* head)
{
	if(!head) return;
	
	struct node *fptr=head->next,*sptr=head;
	
	while(sptr && fptr && fptr->next)
	{ if(sptr==fptr)
	       {
	       	 RemoveLoop(head,sptr);
	       	;return;} 
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