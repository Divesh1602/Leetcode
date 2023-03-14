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
    int helper(TreeNode* root,int n){
        if(root->left==NULL && root->right==NULL){
              n=n*10+root->val;
           return n;
        }
        
        n=n*10+root->val;
        
        int first=0,second=0;
        
        if(root->left)
            first=helper(root->left,n);
        
        if(root->right)
            second=helper(root->right,n);
        return first+second;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};