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
};