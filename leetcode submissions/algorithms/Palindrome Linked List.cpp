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
     ListNode* reverseList(ListNode* head)
    {
        ListNode* cur=head,*prev=NULL,*nex=NULL;
        while(cur)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
          return true;
          ListNode *slow=head,*fast=head;
          while(fast->next && fast->next->next)
          {
              fast=fast->next->next;
              slow=slow->next;
          cout<<slow->val;
              
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
};