vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;
    if (!head) return ans; // Check if head is NULL

    Node* t = head;
    Node* p = head;
    
    // Move p to the last node
    while (p->next != NULL) {
        p = p->next;
    }

    // Two-pointer approach
    while (t != p && t->data < p->data) {
        int sum = t->data + p->data;
        if (sum == k) {
            ans.push_back({t->data, p->data});
            t = t->next;
            p = p->prev;
        } 
        else if (sum > k) {
            p = p->prev;
        } 
        else {
            t = t->next;
        }
    }
    return ans;
}