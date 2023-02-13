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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* curr=new TreeNode(val);
        if(root->val<curr->val){
            curr->left=root;
            return curr;
        }
       TreeNode* prev=NULL;
        TreeNode* find=root;
        while(find){
            prev=find;
            find=find->right;
            if(find && find->val<curr->val)
                break;
        }
      
            prev->right=curr;
            curr->left=find;
            
        return root;
    }
};