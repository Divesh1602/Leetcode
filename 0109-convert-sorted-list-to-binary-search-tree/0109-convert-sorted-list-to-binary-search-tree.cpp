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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     pair<ListNode*,ListNode*> findMiddle(ListNode* head){
         if(!head || !head->next)
             return {NULL,head};
         
         ListNode* fast=head,*slow=head;
         ListNode* prev=NULL;
         while(fast && fast->next){
             fast=fast->next->next;
             prev=slow;
             slow=slow->next;
         }
         return {prev,slow};
     }
    
    TreeNode* sortedListToBST(ListNode* head) {
      if(!head)
          return NULL;
        
        pair<ListNode*,ListNode*> p=findMiddle(head);
        ListNode* prev=p.first;
        ListNode* mid=p.second;
        
        TreeNode* root=new TreeNode(mid->val);
        if(prev){
            prev->next=NULL;
            root->left=sortedListToBST(head);
        }
        root->right=sortedListToBST(mid->next);
        return root;
    }
};