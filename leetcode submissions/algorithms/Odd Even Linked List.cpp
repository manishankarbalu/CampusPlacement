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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head)
           return NULL;
        if(!head->next)
           return head;
        ListNode *eHead,*oHead,*eptr,*optr,*ptr;
        optr=head;
        eHead=eptr=head->next;
        ptr=eptr->next;
        int i=1;
        while(ptr)
        {
            if(i&1)
            {
              optr->next=ptr;
              optr=optr->next;
            }
              
             else
               {
                   eptr->next=ptr;
                   eptr=eptr->next;
               }
            ptr=ptr->next;  
            i++;
            
        }
        optr->next=eHead;
        eptr->next=NULL;
        return head;
    }
};