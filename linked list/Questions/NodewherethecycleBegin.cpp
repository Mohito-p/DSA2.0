class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
               ListNode* t=head;
               while(t!=slow){
                   slow=slow->next;
                   t=t->next;
               }
               return t;
            }
        }
        return NULL;
        
    }
};