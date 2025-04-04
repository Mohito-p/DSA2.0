//Recursive approach

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;
        ListNode* curr = head;
        int cnt = 0;
        while (cnt < k) {
            if (curr == NULL) return head;  // If nodes are less than k, return as it is
            curr = curr->next;
            cnt++;
        }
        
        // Reverse k nodes
        ListNode* prev = reverseKGroup(curr, k);  // Reverse the remaining part
        curr = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            cnt++;
        }
        
        return prev;  // New head after reversal
    }
};
