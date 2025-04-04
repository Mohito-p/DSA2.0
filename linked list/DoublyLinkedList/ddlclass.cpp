  #include<bits/stdc++.h>
using namespace std;
class Node{ // user define data type
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class DLL{ //user define data structure
public:
     Node* head;
     Node* tail;
     int size;
     DLL(){
        head = tail = NULL;
        size=0;
     }
     void insertAtTail(int val){
         Node* temp = new Node(val);
         if(size==0){
            head = tail =temp;
         }
         else{
            tail->next = temp;
            temp->prev = tail;//extra
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
     void insertAtHead(int val){
            Node* temp=new Node(val);
            if(size==0){
               head=tail=temp;
            }
            else{
                temp->next=head;
                head->prev=temp;//extra
                head=temp;
            }
            size++;
     }

     void insertAt_index(int val,int k){
        if(k<0 || k>size){
            return ;
        }
        else if(k==0){
            insertAtHead(val);
        }
        else if(k==size){
            insertAtTail(val);
        }
        else{
        Node* temp=new Node(val);
        Node* t=head;
        for(int i=0;i<k-1 ;i++){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
         temp->prev=t;
        t->next->prev=temp;
       
        
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
   DLL ll ; //{}
   ll.insertAtTail(10);
   ll.insertAtTail(50);
   ll.insertAtTail(40);
   ll.display();
   ll.insertAtTail(20);
   ll.display();
   ll.insertAtHead(70);
   ll.display();
   ll.insertAt_index(30 , 1);
   ll.display();
   //cout<< ll.get(3);
    return 0;
}