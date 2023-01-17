/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     bool hasCycle(ListNode *head) {
      ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
       if(hasCycle(head)){
           unordered_map<const ListNode*,int> m;
           ListNode* curr=head;
           while(curr!=NULL){
               if(m[curr]>0)
                   return curr;
               m[curr]++;
               curr=curr->next;
               
           }
       }
        return NULL;
    }
};