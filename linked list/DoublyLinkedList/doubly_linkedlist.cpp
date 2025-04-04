#include<bits/stdc++.h>
using namespace std;
class Node{
public:
       int val;
       Node* next;
       Node* prev;
       Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
       }
};
void display(Node* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
void display(Node* tail){
    while(tail){
        cout<<tail->val<<" ";
        tail=tail->prev;
    }
    cout<<endl;
}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    Node* e=new Node(50);
    Node* f=new Node(60);
    a->next=b;
    b->next=c;
    b->prev=a;
    c->next=d;
    c->prev=b;
    d->next=e;
    d->prev=c;
    e->next=f;
    e->prev=d;
    f->prev=e;
    display(a);

    return 0;
}