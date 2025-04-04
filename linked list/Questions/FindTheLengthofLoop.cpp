/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
               Node* t=head;
               while(t!=slow){
                   slow=slow->next;
                   t=t->next;
               }
               int len=1;
               Node* z=t->next;
               while(z!=t){
                   len++;
                   z=z->next;
               }
               return len;
            }
        }
        return 0;
    }