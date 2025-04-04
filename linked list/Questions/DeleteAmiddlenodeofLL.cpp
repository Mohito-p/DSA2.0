class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) { 
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* t=head;
        while(t->next!=slow){
            t=t->next;
        }
        t->next=t->next->next;
        return head;
    }
};