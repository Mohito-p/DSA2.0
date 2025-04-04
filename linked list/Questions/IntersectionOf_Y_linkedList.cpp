//there are three approaches

//aproach one (using hashing)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(headA==NULL || headB==NULL) return NULL;
        unordered_map<ListNode*>mp;
        while(headA!=NULL){
            mp[headA]=1;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(mp.find(headB)!=mp.end()) return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

// approach two
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(d){
            d--;
            t2=t2->next;
        }
        while(t1!=t1){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
};

// approach three(Best)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){

            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2) return temp1;

            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
    }
};