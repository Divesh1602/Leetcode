/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int size=0;
        ListNode* curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        size=size/2;
        ListNode* prev=NULL;
        curr=head;
        int pos=-1;
        while(curr!=NULL){
            pos++;
            if(pos==size)
                break;
            prev=curr;
            curr=curr->next;
        }
        if(curr==head){
            head=curr->next;
        }
       else if(curr->next==NULL){
            prev->next=NULL;
        }
        else{
            ListNode* temp=curr->next;
            prev->next=temp;
            curr->next=NULL;
            delete(curr);
        }
        return head;
    }
};