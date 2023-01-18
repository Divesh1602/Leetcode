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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val > curr->next->val)
                curr->next=curr->next->next;
            else
                curr=curr->next;
        }
        head=reverse(head);
        return head;
    }
};