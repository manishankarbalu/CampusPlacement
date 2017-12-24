//Linked List creation
struct node
{
	int data;
	struct node *next;
}

//Function returning a  a new Node
struct node* newNode(int value)
{
	struct node* temp=new node;
	temp->data=value;
	temp->next=NULL;
	return temp;
}

void insertAtBegining(struct node* &head,int value)
{
	struct node* temp=newNode(value);
	temp->next=head;
	head=temp;
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
void insertAtPos(struct node* &head,int value,int pos)
{
    struct node* temp=newNode(value);
	int t=0;
	struct node* ptr=head;
	while(ptr->next!=NULL && t<pos-2)
	{
     ptr=ptr->next;
     t++;
	}
	temp->next=ptr->next;
    ptr->next=temp;
}
void insertAfterVal(struct node* &head,int value,int value1)
{
    struct node* temp=newNode(value);
	struct node* ptr=head;
	while(ptr->next!=NULL && ptr->data!=value1)
	{
     ptr=ptr->next;
	}
	temp->next=ptr->next;
    ptr->next=temp;
}
void deleteAtEnd(struct node* &head)
{
 	struct node* ptr=head;
	struct node* temp;
     while(ptr->next->next!=NULL)
	{
     ptr=ptr->next;
	}
	temp=ptr->next;
        ptr->next=NULL;
       free(temp);  
}
void deleteAtPos(struct node* &head,int pos)
{
    struct node* temp;
	int t=0;
	struct node* ptr=head;
	while(ptr->next!=NULL && t<pos-2)
	{
     ptr=ptr->next;
     temp=ptr->next;
	}
	ptr->next=temp->next;
    free(ptr->next);
}
//print linked list
void printLinkedList(struct node* head)
{
	struct node* ptr=head;
	while(ptr)
	{
		cout<<ptr->data<<" , ";
		ptr=ptr->next;
	}
}

//sample main()
int main()
{
 struct node* head=newNode(1);
 printLinkedList(head) ;
cout<<endl;
 insertAtBegining(head,0);
 printLinkedList(head);
cout<<endl;
 insertAtEnd(head,2);
 insertAtEnd(head,4);
 insertAtEnd(head,6);
 printLinkedList(head);
cout<<endl;
 insertAtPos(head,3,4);
 printLinkedList(head);
 cout<<endl;
 insertAfterVal(head,5,4);
 printLinkedList(head);
 cout<<endl;
 /*deleteAtEnd(head);
 printLinkedList(head);
 cout<<endl;
 deleteAtPos(head,4);
 printLinkedList(head);
 cout<<endl;*/

return 1;
}

//Swap 2 nodes by breaking its links (theres a doubt)

void swapLinks(struct node* &head, int val1, int val2)
{
      if(!head)
      	 return;
      struct node *xptr=NULL,*yptr=NULL,*x=NULL,*y=NULL,*ptr=head;
  
      while(ptr->next)
      {
      	if(ptr->next->data==val1)
      	{
           xptr=ptr;
      	}
      	if(ptr->next->data==val2)
      	{
      		yptr=ptr;
      	}
      	ptr=ptr->next;
      }
    if(xptr && yptr)
    {
      x=xptr->next;
      y=yptr->next;
    }
    else
    {
    	return;
    }
    ptr=y->next;

    xptr->next=y;
    yptr->next=x;
    y->next=x->next;
    x->next=ptr;
    
}

//count the number of nodes in linked list (Recursion)

int countNodesRecursive(struct node* ptr)
{
	if(!ptr)
		return 0;
    return countNodesRecursive(ptr->next)+1;
}

//count the number of nodes in linked list (iteration)

void countNodesIterative(struct node* head)
{
	int count=0;
    struct node* ptr=head;
	while(ptr)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}

//Middle of a linked list

struct node* findMiddleElement(struct node* head)
{
	if(!head)
		return NULL;
	struct node* fast=head;
	struct node* slow=head;
    
    while(fast->next && fast->next->next)
    {
    	fast=fast->next->next;
    	slow=slow->next;
    }
    return slow;
}

//Remove nth Node from end given n is valid

void removeNthNodeFromEnd(struct node* &head,int pos)
{
	struct node *fast=head,*slow=head;
	int t=0;
	while(t<pos)
	{
      fast=fast->next;t++;
	}
	if(fast==NULL)
	{
		head=head->next;
		delete(slow);
		return;
	}
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
    struct node* temp=slow->next;
    slow->next=temp->next;//slow->next->next;
    delete(temp);
}

//Reverse a linked list (iteratively)

void reverseIteratively(struct node* &head)
{
	struct node *current=head,*prev=NULL,*next=NULL;

	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;   
}

//Reverse a linked list (Recursive)

void reverseRecursively(struct node* &head)
{
   if(!head)
   	  return;
   	
   	struct node *first=head;
   	struct node *rest=head->next;

   	if(!rest)
   		return ;

   	reverseRecursively(rest);

   	first->next->next=first;

   	first->next=NULL;
   	head=rest;
}

//Another method
struct node* recurrev(struct node *ptr,struct node *&head)
{
	if(ptr->next==NULL)
	{
		head=ptr;
		ptr->next=NULL;
		return ptr;
	}
	recurrev(ptr->next,head)->next=ptr;
	ptr->next=NULL;
	return ptr;
}
struct node* recur(struct node* head)
{
	if(!head || !head->next)
		return head;
	return recurrev(head,head);
}

//detect loop in a linked list

struct node* detectLoop(struct node* head)
{
	struct node *slow=head,*fast=head;
    
    while(slow && fast && fast->next)
    {
    	fast=fast->next->next;
    	slow=slow->next;
    	if(slow==fast)
    		return slow;
    }
return NULL;
}

//Sort two merged linked list

struct node* mergeTwoList(struct node *head1,struct node* head2)
{
	if(!head1)
		return head2;
	else
		if(!head2)
			return head1;

	struct node* sortedHead=NULL;

	if(a->data>b->data)
	{
		sortedHead=a;
		sortedHead->next=mergeTwoList(head1->next,head2);
	}
	else
	{
		sortedHead=b;
		sortedHead->next=mergeTwoList(head1,head2->next);
	}
	return sortedHead;
}

//Check if the liked list is palindrome
struct node* reverseList(struct node* head)
    {
        struct node* cur=head,*prev=NULL,*nex=NULL;
        while(cur)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    bool isPalindrome(struct node* head)
    {
        if(!head)
          return true;
          struct node *slow=head,*fast=head;
          while(fast->next && fast->next->next)
          {
              fast=fast->next->next;
              slow=slow->next;              
          }
          slow->next=reverseList(slow->next);
          slow=slow->next;
          
          while(slow)
          {
              if(head->val!=slow->val)
               return false;
               head=head->next;
               slow=slow->next;
          }
          return true; 	
    }

//swap nodes in pairs

struct node* swapNodeInPairs(struct node* head)
{
     struct node** ptr=&head,*a,*b;
     
     while((a=*ptr)&&(b=a->next))
     {
        a->next=b->next;
        b->next=a;
        *ptr=b;
        ptr=&(a->next);
     }
     return head;
}

//Recursive function to print reverse of linked list

void printReversePathRecursively(struct node* head)
{
   if(!head)
   	  return;
   	printReversePathRecursively(head->next);
   	cout<<head->data;
}

//Remove duplicate from sorted linked list

void removeDuplicateSortedList(struct node* &head)
{
	if(!head)
		return;
	struct node *a=head,*b=a->next;
    while(a && b)
    {
    	b=a->next;
    	if(a->data==b->data)
    	{
    		a->next=b->next;
    		delete(b);
    	}
    	else
    	{
    		a=a->next;
    		b=a->next;
    	}
    }
}

//Move last element to front of linked list

void moveLastToFront(struct node* &head)
{
	if(!head)
		return;
	struct node *ptr=head,*temp=NULL;
	while(!ptr->next)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	ptr->next=head;
	head=ptr;
}

//create a new linked list with all intersecting nodes
   // of 2 different linked list

vecotor<int> findIntersectingNodes(struct node* a,struct node* b)
{
	vector<int> v;
	
    int i=0;
    
    while(a && b)
    {
      if(a->data==b->data)
      {
		v.push_back(a->data);
		a=a->next;
		b=b->next;     
      }
     else
          if(a->data>b->data)
	      {
	      	b=b->next;
	      }
	      else
	      	if(a->data<b->data)
	      	{
	          a=a->next;
	      	}
    }
return v;
}

//Check if two Linked Lists are identical

void identical(struct node* a,struct node* b)
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

//Reverse a Linked List in group of given size

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

//find the intersection point of 2 ll (Y shape)
  // some smart ans but time consuming

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}

//odd even linked list

struct node* oddEvenLL(struct node* head)
{
	if(!head)
		return NULL;
	if(!head->next)
		return head;
	struct node *optr,*eptr,*eHead;
	optr=head;
	eptr=eHead=head->next;
	while(eptr->next && eptr->next->next)
	{
		optr->next=optr->next->next;
		eptr->next=eptr->next->next;
		optr=optr->next;
		eptr=eptr->next
	}
	optr->next=eHead;
	return head;
}

struct node* reverseAlternateGroup(struct node* &head,int k)
{
	if(!head)
		return NULL;
	struct node *current=head,*prev=NULL,*next=NULL;
    int i=0;
    while(current && i<k)
    {
    	next=current->next;
    	current->next=prev;
    	prv=current;
    	current=next;
    	i++;
    }
   
    if(head)
    	head->next=current;
    i=0;
    while(current && i<k-1)
    {
    	current=current->next;
    	i++;
    }
    if(current)
    	current->next=reverseAlternateGroup(current->next,k);
    
    return prev;
}

//Delete all greater nodes in right side

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

void deleteGreaterRightNodes(struct node* &head)
{
	if(!head || !head->next)
		return head;
	reverseList(head);
    struct node* slow=head,*fast=head->next;
    while(fast)
    {
    	if(fast->data<slow->data)
    	{
    		slow->next=fast->next;
    		delete(fast);
    		fast=slow->next;
    	}
    	else
    	{
    		slow=slow->next;
    		fast=slow->next;
    	}
    }
    reverseList(head);
}

//Add two numbers represented by linked list

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
        if(!res)
        	{res=temp;ptr=res;}
        else
        	ptr->next=temp;
        ptr=temp;

        if(a) a=a->next;
        if(b) b=b->next;
    }
    if(carry>0)
    	temp->next=newNode(carry);
    return result;
}

main()
{
	struct node *a,*b;
	reverseList(a);
	reverseList(b);
	struct node* res=addTwoList(a,b);
    reverseList(res);
}

//add 1 to a number rep as linked list

int addOneToList(struct node* &head)
{
	if(!head)
		return 1;
	int res=head->data+addOneToList(head->next);

	head->data=res%10;

	return res/10;

}

struct node* addOne(struct node* &head)
{
	int carry=addOneToList(head);

	if(carry)
	{
		struct node* temp=newNode(carry)
		temp->next=head;
		head=temp;
	}
	return head;
}

//point arbitrary pointer to greatest value on right

struct node* pointArbitraryPointer(struct node* head)
{
	head = reverse(head);
 
    Node *max = head;
 
    Node *temp = head->next;
    while (temp != NULL)
    {
        temp->arbit = max;
        if (max->data < temp->data)
            max = temp;
        temp = temp->next;
    }
    return reverse(head);
}

//merge 2 linked list alternately 2 list shouldnt be altered

/*
First Linked List:
1 2 3
Second Linked List:
4 5 6 7 8
Modified First Linked List:
1 4 2 5 3 6
Modified Second Linked List:
7 8 */

void mergeTwoListAlternately(struct node* &a,struct node* &b)
{
	if(!a || !b)
		return;
    struct node *acur=a,*anex,*bcur=b,*bnex;
	while(acur && bcur)
	{
		anex=acur->next;
        bnex=bcur->next;
		acur->next=bcur;
		bcur->next=anex;

		acur=anex;
		bcur=bnex;	
	}
b=bcur;
}

//mergesort for linked list
public class Solution {
  
  public ListNode sortList(ListNode head) {
    if (head == null || head.next == null)
      return head;
        
    // step 1. cut the list to two halves
    ListNode prev = null, slow = head, fast = head;
    
    while (fast != null && fast.next != null) {
      prev = slow;
      slow = slow.next;
      fast = fast.next.next;
    }
    
    prev.next = null;
    
    // step 2. sort each half
    ListNode l1 = sortList(head);
    ListNode l2 = sortList(slow);
    
    // step 3. merge l1 and l2
    return merge(l1, l2);
  }
  
  ListNode merge(ListNode l1, ListNode l2) {
    ListNode l = new ListNode(0), p = l;
    
    while (l1 != null && l2 != null) {
      if (l1.val < l2.val) {
        p.next = l1;
        l1 = l1.next;
      } else {
        p.next = l2;
        l2 = l2.next;
      }
      p = p.next;
    }
    
    if (l1 != null)
      p.next = l1;
    
    if (l2 != null)
      p.next = l2;
    
    return l.next;
  }

}


//reorder list 1-2-3-4 as 1-4-2-3
void reorderList(ListNode *&head)
    {
  
    if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    ListNode *cur=head2,*prev=NULL,*next=NULL;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        p2=prev;
    
    // merge two lists: O(n)
    for (p1 = head, p2 = prev; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
     //   return head;
    }

//reverse linked list between given positions m and n
ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n)return head;
	n-=m;
    ListNode prehead(0);
    prehead.next=head;
    ListNode* pre=prehead;
    while(--m)pre=pre->next;        
    ListNode* pstart=pre->next;
    while(n--)
    {
        ListNode *p=pstart->next;
        pstart->next=p->next;
        p->next=pre->next;
        pre->next=p;
    }
    return prehead.next;
}    

// delete all duplicates eg 1-1-2 gives 2 similarly 1-2-2-3-3-4-5 gives 1-4-5

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head || !head->next)
           return head;
        ListNode *p1=head,*p2=head->next,*root=new ListNode(0),*ptr=root,*p;bool flag=true;
        while(p2)
        {
            if(p1->val!=p2->val)
            {
                ptr->next=p1;
                p1=p1->next;
                p2=p2->next;
                ptr=ptr->next;
                flag=true;
            }
            else
            {   p=p2;
                while(p1->val==p2->val && p2->next)
                {p=p2;p2=p2->next;}
                p1=p2;
                p2=(p2->next)?p2->next:NULL;
                flag=false;
            }
        }
        if(flag)ptr->next=p1;
        else
            if(p->val!=p1->val)
                ptr->next=p1;
             else   ptr->next=NULL;
        return root->next;
    }