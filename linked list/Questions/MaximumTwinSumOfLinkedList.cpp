class Solution {
    private:
        ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
public:
    int pairSum(ListNode* head) {
        //Finding the Length of the LinkedList
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        //finding the middle of the 
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            if(fast->next->next==NULL){
                slow=slow->next;
                fast=fast->next;
            }
            else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        ListNode dummy=(0,NULL);
        dummy.next=slow;
        temp=head;
         ListNode* newhead=reverseList(dummy.next);
         int maxi=0;
         int total=0;
         for(int i=0;i<=(n/2)-1;i++){
            total=temp->val+newhead->val;
            maxi=max(total,maxi);
            temp=temp->next;
            newhead=newhead->next;
         }
         return maxi;
    }
};