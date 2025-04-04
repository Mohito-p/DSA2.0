#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Given the head of a list, reverse the list and return the
// head of reversed list
Node* reverseList(Node* head) {
    
      // Initialize three pointers: curr, prev and next
    Node *curr = head, *prev = nullptr, *next;

      // Traverse all the nodes of Linked List
    while (curr != nullptr) {
      
        // Store next
        next = curr->next;
      
        // Reverse current node's next pointer
        curr->next = prev;
      
        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }
      
      // Return the head of reversed linked list
    return prev;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked list:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);

    return 0;
}

//recursion

Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest of linked list and put the first element at the end 
    Node* rest = reverseList(head->next);
  
      // Make the current head as last node of remaining linked list
    head->next->next = head;

      // Update next of current head to NULL
    head->next = NULL;

       // Return the reversed linked list
    return rest;
}

//Stack

Node* reverseList(Node* head) {
      
    // Create a stack to store the nodes
    stack<Node*> s;
  
    Node* temp = head;
  
      // Push all nodes except the last node into stack
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }
      
      // Make the last node as new head of the linked list
    head = temp;
  
      // Pop all the nodes and append to the linked list
    while (!s.empty()) {
          
        // append the top value of stack in list
        temp->next = s.top();
        
          // Pop the value from stack
        s.pop();
        
          // move to the next node in the list
        temp = temp->next;
    }
      
      // Update the next pointer of last node of stack to NULL
    temp->next = NULL;
  
      return head;
}