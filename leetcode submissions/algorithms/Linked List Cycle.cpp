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
    bool hasCycle(ListNode *head) {
        struct ListNode *fptr=head;
        struct ListNode *sptr=head;
        while(sptr && fptr && fptr->next)
        {
            sptr=sptr->next;
            fptr=fptr->next->next;
            if(fptr==sptr)
            return true;
        }
        return false;
    }
};