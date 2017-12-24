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
    ListNode* reverseList(ListNode* head) {
        //if (!head) return head;
        //ListNode* first = head;
        struct ListNode* rest;//=first->next;
       if(head==NULL) return NULL;
        if (head->next==NULL) return head;
        rest=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
 
        
    }
};