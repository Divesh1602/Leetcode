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
    TreeNode* prev=NULL;
    bool flag=true;
    void inorder(TreeNode* root,int &ans){
        if(root){
            inorder(root->left,ans);
            if(flag)
            {
                prev=root;
                flag=false;
            }
            else{
                ans=min(ans,root->val-prev->val);
                prev=root;
                }
            inorder(root->right,ans);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        inorder(root,ans);
        return ans;
    }
};