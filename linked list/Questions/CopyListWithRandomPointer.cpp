/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            mp[temp]=copy;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node* copynode=mp[temp];
            copynode->next=mp[temp->next];
            copynode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];

    }
};

//approach second

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        //copy node inserted
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        //connect random pointers
        temp=head;
        while(temp!=NULL){
            Node* copy=temp->next;
           if(temp->random!=NULL) copy->random=temp->random->next;
            temp=temp->next->next;
        }
        //seperate original and copied lists
        Node* dummy=new Node(0);
        temp=head;
        Node* res=dummy;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
