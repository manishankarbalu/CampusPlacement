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
bool identical(struct node* a,struct node* b)
{
	if(a==NULL && b==NULL)
		return true;
	if(a && b)
			return ( (a->data==b->data) 
	               &&  identical(a->next,b->next)  
			);
    else
    	return false;
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
//cout<<"ent"<<endl;    
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

 struct node* b=newNode(0);
 insertAtEnd(b,0);
 insertAtEnd(b,1);
 //insertAtEnd(b,8);
 printLinkedList(b) ;
 cout<<endl;

/* if(identical(a,b))
    cout<<"identi";
else cout<<"not";  


  struct node *intersect=findIntersectingNodes(a,b);
*/
reverseList(a);
reverseList(b);
  struct node* res=addTwoList(a,b);
reverseList(res);  
printLinkedList(res);
  cout<<endl;

return 1;
}
