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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p;
        ListNode *res=NULL;
        int s=0,c=0;
        while(l1 || l2)
        {   s=0;
            int val1=0,val2=0;
            val1=(l1)?l1->val:0;
            val2=(l2)?l2->val:0;
            s=val1+val2+c;
            c=(s>=10)?1:0;
            s%=10;
            cout<<val1<<val2<<s<<c<<endl;
            if(!res)
            {
                res=new ListNode(s);
                p=res;
            }
            else
            {
                ListNode* temp=new ListNode(s);
                p->next=temp;
                p=p->next;
            }
            l1=(l1)?l1->next:NULL;
            l2=(l2)?l2->next:NULL;
        }
        if(c>0)
        {
            ListNode* temp=new ListNode(c);
                p->next=temp;
                p=p->next;
        }            
        return res;
    }
};