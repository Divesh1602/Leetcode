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
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* pre=NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        
        return pre;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=rev(slow->next);
        ListNode* h=slow->next;
        slow->next=NULL;
        slow=h;
        ListNode* curr=head;
       
        while(slow!=NULL){
            ListNode* temp=curr->next;
            ListNode* ptr=slow->next;
            curr->next=slow;
            slow->next=temp;
            curr=temp;
            slow=ptr;
         
        }
       
        
    }
};