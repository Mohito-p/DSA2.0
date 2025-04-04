#include<bits/stdc++.h>
using namespace std;
class Node{ // user define data type
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LinkedList{ //user define data structure
public:
     Node* head;
     Node* tail;
     int size;
     LinkedList(){
        head = tail = NULL;
        size=0;
     }
     void insertAtEnd(int val){
         Node* temp = new Node(val);
         if(size==0){
            head = tail =temp;
         }
         else{
            tail->next = temp;
            tail = temp;
         }
         size++;
     }
     void display(){
         Node* temp = head;
         while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
         }
         cout<<endl;
     }
     void insertAtBeginning(int val){
            Node* temp=new Node(val);
            if(size==0){
               head=tail=temp;
            }
            else{
                temp->next=head;
                head=temp;
            }
            size++;
     }

     void insertAt_kthPosition(int val,int k){
        if(k<0 || k>size){
            return ;
        }
        else if(k==0){
            insertAtBeginning(val);
        }
        else if(k==size){
            insertAtEnd(val);
        }
        else{
        Node* temp=new Node(val);
        Node* t=head;
        for(int i=0;i<k-1 ;i++){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
        }
        size++;
     }
     int get(int k){
          if(k<0 || k>size){
            return -1;
          }
          else if(k==0){
            return head->val;
          }
          else if(k==size-1){
            return tail->val;
          }
          else{
             Node* t=head;
             for(int i=0;i<k;i++){
                t=t->next;
             }
             return t->val;
          }
     }
};

int main(){
   LinkedList ll ; //{}
   ll.insertAtEnd(10);
   ll.insertAtEnd(50);
   ll.insertAtEnd(40);
   ll.display();
   ll.insertAtEnd(20);
   ll.display();
   ll.insertAtBeginning(70);
   ll.display();
   ll.insertAt_kthPosition(30 , 1);
   ll.display();
   cout<< ll.get(3);
    return 0;
}