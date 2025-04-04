#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* RemoveNodePresentInNums(ListNode* head, vector<int> nums) {
    if (!head) return NULL;
    unordered_set<int> s(nums.begin(), nums.end());
    while (head && s.count(head->val)) {
        head = head->next;
    } 
    ListNode* temp = head;
    while (temp && temp->next) {
        if (s.count(temp->next->val)) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    
    vector<int> nums = {1};
    head = RemoveNodePresentInNums(head, nums);
    
    printList(head);
    return 0;
}