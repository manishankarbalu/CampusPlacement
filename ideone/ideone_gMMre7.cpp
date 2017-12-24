#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct node
{
    int data;
    struct node* next, *arbit;
};
void reverse(struct node *&head)
{
	if(!head)
	   return;
	   
    struct node *first=head,*res = head->next;
    
    if(!res)
       return;
    reverse(res);   
    first->next->next=first;
    first->next=NULL;
    head=res;
    
}
 
struct node* pointArbitraryPointer(struct node* head)
{
	if(!head)
		return NULL;
	if(!head->next)
		return head;
	reverse(head);
    struct node* ptr=head,*great=head;
    while(ptr)
    {
    	if(ptr->data>great->data)
    	{
    		ptr->arbit=great;
    		great=ptr;
    	}
    	else
    		if(ptr->data<great->data)
    		{
    			ptr->arbit=great;
    		}
    ptr=ptr->next;		
    } 
    reverse(head);
    return head;
} 
/* Function to reverse the linked list */

 

 
// Utility function to print result linked list
void printNextArbitPointers(struct node *node)
{
    printf("struct node\tNext Pointer\tArbit Pointer\n");
    while (node!=NULL)
    {
        cout << node->data << "\t\t";
 
        if (node->next)
            cout << node->next->data << "\t\t";
        else cout << "NULL" << "\t\t";
 
        if (node->arbit)
            cout << node->arbit->data;
        else cout << "NULL";
 
        cout << endl;
        node = node->next;
    }
}
 
/* Function to create a new node with given data */
struct node *newNode(int data)
{
    struct node *new_node = new struct node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);
 
    head = pointArbitraryPointer(head);
 
    printf("Resultant Linked List is: \n");
    printNextArbitPointers(head);
 
    return 0;
}