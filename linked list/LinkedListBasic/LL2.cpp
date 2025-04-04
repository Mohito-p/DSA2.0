#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
void display(Node* head){
     Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int size(Node* head){
    int size=0;
     Node * temp=head;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    cout<<size<<endl;
}
void insertAtEnd(int x,Node* head){
     Node *t= new Node(x);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=t;
     
}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    Node* e=new Node(50);
   
    a->next =b;
    b->next =c;
    c->next =d;
    d->next =e;
    cout<<a->next->next->next->val;
   display(a);
   cout<<size(a);
   insertAtEnd(60,a);
   display(a);
    return 0;
}