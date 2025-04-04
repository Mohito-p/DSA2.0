/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *reverse(Node *head) {
    Node *prev = nullptr, *curr = head, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *trimLeadingZeros(Node* head) {
    while(head->next != nullptr && head->data == 0)
        head = head->next;
    return head;
}
Node *addOne(Node *num1)
{
    num1 = trimLeadingZeros(num1);

    int carry = 0;
    num1 = reverse(num1);
    Node *res = num1;
    int add=1;

while (add!=0 || carry != 0) {
      

        num1->data += carry;
        num1->data +=add;
        add=0;
      

        carry = num1->data / 10;
          

        num1->data = num1->data % 10;

        if(num1->next == nullptr && carry != 0)
            num1->next = new Node(0);
      
        num1 = num1->next;
    }
    return reverse(res);
}