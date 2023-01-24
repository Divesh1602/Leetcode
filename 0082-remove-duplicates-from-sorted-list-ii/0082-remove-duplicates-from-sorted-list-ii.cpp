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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* newList=new ListNode();
        ListNode* cur=newList;
        while(curr!=NULL){
             if(curr!=NULL && curr->next==NULL){
                cur->next=new ListNode(curr->val);
                cur=cur->next;
                curr=curr->next;
            }
           else if(curr->val==curr->next->val){
                int temp=curr->val;
                while(curr && curr->val==temp){
                    curr=curr->next;
                }
            }
           
            else{
                cur->next=new ListNode(curr->val);
                cur=cur->next;
                curr=curr->next;
            }
        }
        return newList->next;
    }
};