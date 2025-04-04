class BrowserHistory {
public:
    struct Node {
        string val;
        Node* back;
        Node* next;
        Node(string v) : val(v), back(nullptr), next(nullptr) {}
    };
    
    Node* head;
    
    BrowserHistory(string homepage) {
        head = new Node(homepage);
    }
    
    void visit(string url) {
        Node* visiter = new Node(url);
        head->next = visiter;
        visiter->back = head;
        head = visiter; // Move head to the newly visited page
    }
    
    string back(int steps) {
        while (steps> 0 && head->back) {
            head = head->back;
            steps--;
        }
        return head->val;
    }
    
    string forward(int steps) {
        while (steps > 0 && head->next) {
            head = head->next;
            steps--;
        }
        return head->val;
    }
};
