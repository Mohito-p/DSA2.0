class Solution {
    private:
        int rev(ListNode* last,ListNode* head,int n){
            if (!head) return 0;
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* Next=curr->next;
            int count=0;
            while(curr !=NULL && n>0){
                Next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=Next;
                n--;
                count++;
            }
            head->next=Next;
            last->next=prev;
            return count;
        }
    public:
        ListNode* reverseEvenLengthGroups(ListNode* head) {
            int gn=0, elementPrevGroup=0;
            ListNode* curr = head;
            ListNode* lastPrevGroup=NULL;
            ListNode* lastOfEvenGroup=NULL;
            while(curr != NULL){
                gn++;
                if(gn % 2 == 0){
                   elementPrevGroup = rev(lastPrevGroup,curr,gn);
                   lastOfEvenGroup=curr;
                   curr=curr->next;
                }
                else{
                    int k=gn;
                    elementPrevGroup=0;
                    while(curr !=NULL && k>0){
                        lastPrevGroup=curr;
                        curr=curr->next;
                        k--;
                        elementPrevGroup++;
                    }
                }
            }
            if(gn % 2==1 && elementPrevGroup % 2==0){
               rev(lastOfEvenGroup,lastOfEvenGroup->next,elementPrevGroup);
            }else if(gn % 2==0 && elementPrevGroup % 2==1){
               rev(lastPrevGroup,lastPrevGroup->next,elementPrevGroup);
            }
        return head;
        }
    };