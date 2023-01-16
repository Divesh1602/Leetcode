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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            if(curr->val==val){
                ListNode* next=curr->next;
                ListNode* temp=curr;
                if(curr == head)
                    head=next;
                else{
                    prev->next=next;
                }
                temp->next=NULL;
                delete(temp);
                curr=next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};