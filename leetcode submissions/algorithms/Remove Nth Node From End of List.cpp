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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *ptr=head,*temp=head;int t=0;
        
        while(t<n)
        {
            ptr=ptr->next;
            t++;
        }
       // cout<<ptr->val;
        if(ptr==NULL)
        {
            head=head->next;
            delete(temp);
            return head;
        }
        while(ptr->next!=NULL)
        {
            temp=temp->next;
            ptr=ptr->next;
        }
        
        delete(temp->next);
        temp->next=temp->next->next;
        
        return head;
        
    }
};