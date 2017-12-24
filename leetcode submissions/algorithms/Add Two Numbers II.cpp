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
     
        ListNode *ans=new ListNode(0),*temp;int i=0,sum=0;
        stack<int> s1,s2;
        
        while(l1)
            {s1.push(l1->val);l1=l1->next;}
        
        while(l2)
            {s2.push(l2->val);l2=l2->next;}
        int c=0;
        while(!s1.empty() || !s2.empty())
        {   int n1=0,n2=0;
            
         if(!s1.empty())
                {n1=s1.top();s1.pop();}

            if(!s2.empty())
                {n2=s2.top();s2.pop();}
        
         sum+=(n1+n2);
         
         ans->val=(sum%10);
             temp=new ListNode(sum/=10);
             temp->next=ans;
             ans=temp;
        }
        
     return (ans->val)?ans:ans->next;   
    }
};