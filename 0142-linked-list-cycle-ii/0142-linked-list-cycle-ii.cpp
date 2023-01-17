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
    ListNode *detectCycle(ListNode *head) {
      
           unordered_map<const ListNode*,int> m;
           ListNode* curr=head;
           while(curr!=NULL){
               if(m[curr]>0)
                   return curr;
               m[curr]++;
               curr=curr->next;
               
           }
       
        return NULL;
    }
};