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
    bool sol(TreeNode * rootl,TreeNode * rootr){
        //base case
        if(rootl==NULL || rootr==NULL){
            if(rootl==NULL && rootr==NULL){
            return true;
            }
            else{
            return false;
            }
        }
        
        bool a,b;
        if(rootl->val==rootr->val){
            a=sol(rootl->left,rootr->right);
            b=sol(rootl->right,rootr->left);
        }
        else
        return false;
        if(a && b)
        return true;
        else
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        
        return sol(root->left,root->right);
    
    }
};