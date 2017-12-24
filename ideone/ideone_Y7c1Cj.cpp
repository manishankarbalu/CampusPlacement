     #include<iostream>
    #include<stdio.h>
    #include<stdlib.h>
    using namespace std;
    /* A linked list node */
    struct node
    {
        int data;
        struct node *next;
    };
     
    /* Function to swap nodes x and y in linked list by
       changing links */
    void pairswap(struct node* &head)
    {
    	if(!head || !head->next)
    	   return;
    	struct node ** ptr=&head,*a,*b;
    	
    	while((a=*ptr)&&(b=a->next))
    	{
    		a->next=b->next;
    		b->next=a;
    		*ptr=b;
    		ptr=&(a->next);
    	}
    }
     
    /* Function to add a node at the begining of List */
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
     
    /* Function to print nodes in a given linked list */
    void printList(struct node *node)
    {
        while(node != NULL)
        {
            printf("%d ", node->data);
            node = node->next;
        }
    }
     
    /* Druver program to test above function */
    int main()
    {
        struct node *start = NULL;
     
        /* The constructed linked list is:
         1->2->3->4->5->6->7 */
        push(&start, 7);
        push(&start, 6);
        push(&start, 5);
        push(&start, 4);
        push(&start, 3);
        push(&start, 2);
        push(&start, 1);
     
        printf("\n Linked list before calling swapNodes() ");
        printList(start);
     
        pairswap(start);
     
        printf("\n Linked list after calling swapNodes() ");
        printList(start);
     
        return 0;
    }
