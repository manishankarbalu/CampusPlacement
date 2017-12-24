// C++ program to construct the maximum sum linked
// list out of two given sorted lists
#include<iostream>
using namespace std;
 
//A linked list node
struct Node
{
    int data; //data belong to that node
    Node *next; //next pointer
};
 
int max(int a,int b)
{
	return (a>b)?a:b;
}
// Push the data to the head of the linked list
void push(Node **head, int data)
{
    //Alocation memory to the new node
    Node *newnode = new Node;
 
    //Assigning data to the new node
    newnode->data = data;
 
    //Adjusting next pointer of the new node
    newnode->next = *head;
 
    //New node becomes the head of the list
    *head = newnode;
}
 
// Method that adjusts the pointers and prints the final list
void finalMaxSumList(Node *a, Node *b)
{
	if(!a && !b) return;
	int res=0;int s1=0,s2=0;
	while(a && b)
	{
		if(a->data==b->data)
       {     res+=max(s1,s2)+a->data;
           cout<<s1<<" "<<s2<<" "<<a->data<<endl;s1=0;s2=0;
	      a=a->next;
		  b=b->next;
       }
       else
       {
       	   
       	  if(a->data<b->data)
       	     {
       	     	s1+=a->data;
       	     	a=a->next;
       	     }
        	  if(b->data<a->data)
       	     {
       	     	s2+=b->data;
       	     	b=b->next;
       	     }
       }
       
	}
	s1=0;s2=0;
	while(a)
	  {s1+=a->data;a=a->next;}
	  while(b)
	  {s2+=b->data;b=b->next;}
	res+=max(s1,s2);
cout<<res;	
}
 
//Main driver program
int main()
{
    //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    Node *head1 = NULL, *head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);
 
    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);
 
    finalMaxSumList(head1, head2);
    return 0;
}