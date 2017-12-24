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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if(m==n)return head;
       ListNode* ans=new ListNode(0);
        ans->next=head;
       ListNode *pre=ans,*ps;//,*p=head; 
       n-=m;
       while(--m) pre=pre->next;
       ps=pre->next;
       //ps=prev->next;
      while(n--)
      {
          ListNode *p=ps->next;
          ps->next=p->next;
          p->next=pre->next;
          pre->next=p;
      }
        return ans->next;      
        
    }
};