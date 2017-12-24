/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
		return NULL;
		if(k==1)
		  return head;
	ListNode *current=head,*prev=NULL,*next=NULL;
	int csize=0;
    while(current)
    {
        csize++;
        current=current->next;
    }
    current=head;
    int i=0;
    if(csize-k>=0)
    {
    while(current && i<k)
    {
    	next=current->next;
    	current->next=prev;
    	prev=current;
    	current=next;
    	i++;
    }
    
    if(next)
    	head->next=reverseKGroup(next,k);

    return prev;
    }
    else
    return head;
        
    }
};