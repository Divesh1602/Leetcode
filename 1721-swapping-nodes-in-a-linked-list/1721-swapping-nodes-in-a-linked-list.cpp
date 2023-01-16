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
    ListNode* swapNodes(ListNode* head, int k) {
         int size=0;
        ListNode* curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        curr=head;
        int end=size-k;
        int pos=0;
   
        while(curr!=NULL){
            pos++;
            if(pos==k)
                break;
           
            curr=curr->next;
        }
        ListNode* back=head;
        pos=-1;
        while(back!=NULL){
            pos++;
            if(pos==end)
                break;
            back=back->next;
        }
       int val=curr->val;
        curr->val=back->val;
        back->val=val;
        return head;
    }
};