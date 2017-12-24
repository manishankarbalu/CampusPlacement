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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head)
           return NULL;
        ListNode **ptr=&head,*a,*b;
        while((a=*ptr) && (b=a->next))
        {
            a->next=b->next;
            b->next=a;
            *ptr=b;
            ptr=&(a->next);
        }
        
        return head;
        
    }
};