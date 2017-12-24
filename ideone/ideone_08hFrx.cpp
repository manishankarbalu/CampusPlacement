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

struct node* findIntersectingNodes(struct node* a,struct node* b)
{
	struct node *result=NULL,*reshead=NULL;
    
    bool i=false;
    
	    while(a && b)
	    {
	     
	      if(a->data==b->data)
	      {
	       
		      	if(!i)
		      	{       
		      		reshead=newNode(a->data);
		      		result=reshead;
		      		i=true;
		      	}
		       else
			{
		     
		      	result->next=newNode(a->data);
		      	result=result->next;
			}
	          	
			a=a->next;
		      	b=b->next;
	      
	      }
               else
		      if(a->data > b->data)
		      {
		      	b=b->next;
		      }
		      else
			      	if(a->data < b->data)
			      	{
				  a=a->next;
			      	}
	
	    }

return reshead;
}
int main()
{
 struct node* a=newNode(1);
 insertAtEnd(a,2);
 insertAtEnd(a,3);
 insertAtEnd(a,4);
 insertAtEnd(a,5);
 insertAtEnd(a,6);
 printLinkedList(a) ;
 cout<<endl;

 struct node* b=newNode(2);
 insertAtEnd(b,4);
 insertAtEnd(b,6);
 insertAtEnd(b,8);
 printLinkedList(b) ;
 cout<<endl;

  struct node *intersect=findIntersectingNodes(a,b);

  printLinkedList(intersect);
  cout<<endl;

return 1;
}