// A simple and tail recursive C++ program to reverse
// a linked list
#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    struct node *next;
};
 
void reverseUtil(node* cur,node* pre,node **head)
{
	if(!cur->next)
	{
		*head=cur;
		cur->next=pre;
		return;
	}
	node* next=cur->next;
	cur->next=pre;
	
	reverseUtil(next,cur,head);

}

void reverse(node **head)
{
	if(!head)
	    return;
	reverseUtil(*head,NULL,head);
}
// A utility function to create a new node
node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printlist(node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    cout << "Given linked list\n";
    printlist(head1);
    reverse(&head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}