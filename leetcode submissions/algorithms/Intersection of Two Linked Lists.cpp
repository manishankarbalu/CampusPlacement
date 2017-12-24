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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB)
               return NULL;
        if(headA==headB)
           return headA;
        ListNode *a=headA,*b=headB;
        int count1=0,count2=0;
        while(a)
        {
            count1++;
            a=a->next;
        }
        while(b)
        {
            count2++;
            b=b->next;
        }
        a=headA;b=headB;
        if(count1>count2)
        {
            int diff=count1-count2;
            while(diff)
            {
                a=a->next;
                diff--;
            }
        }
        else
        {
            int diff=count2-count1;
            while(diff)
            {
                b=b->next;
                diff--;
            }
            
        }
        
        while(a && b)
        {
            if(a==b)
               return a;
               
             a=a->next;
             b=b->next;
        }
        return NULL;
    }
};