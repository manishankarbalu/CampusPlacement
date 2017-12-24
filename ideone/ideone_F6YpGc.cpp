#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

//Function returning a  a new Node
struct node* newNode(int value)
{
	struct node* temp=new node;
	temp->data=value;
	temp->next=NULL;
	return temp;
}
void insertAtEnd(struct node* &head,int value)
{
    struct node* temp=newNode(value);
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
     ptr=ptr->next;
	}
	ptr->next=temp;
}
void printLinkedList(struct node* head)
{
	struct node* ptr=head;
	while(ptr)
	{
		cout<<ptr->data<<" , ";
		ptr=ptr->next;
	}
}
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
struct node* addTwoList(struct node* a,struct node* b)
{
	if(!a)
		return b;
	if(!b)
		return a;
    struct node* result=NULL,*temp,*ptr;
    int sum=0,carry=0;
    while(a || b)
    {
    	sum=carry+(a?a->data:0)+(b?b->data:0);
    	carry=sum>=10?1:0;
    	sum=sum%10;
        temp=newNode(sum);
        if(!result)
        	result=temp;
        else
        	ptr->next=temp;
        ptr=temp;
//cout<<sum<<endl;
        if(a) a=a->next;
        if(b) b=b->next;
    }
    if(carry>0)
    	temp->next=newNode(carry);
    return result;
}

int main()
{
 struct node* a=newNode(9);
 insertAtEnd(a,9);
 insertAtEnd(a,9);
 //insertAtEnd(a,4);
 //insertAtEnd(a,6);
 //insertAtEnd(a,8);
 printLinkedList(a) ;
 cout<<endl;

 struct node* b=newNode(1);
 //insertAtEnd(b,0);
 //insertAtEnd(b,1);
 //insertAtEnd(b,8);
 printLinkedList(b) ;
 cout<<endl;


reverseList(a);
reverseList(b);
  struct node* res=addTwoList(a,b);
reverseList(res);  
printLinkedList(res);
  cout<<endl;

return 1;
}