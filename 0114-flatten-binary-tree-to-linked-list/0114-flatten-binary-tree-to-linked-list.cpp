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
    stack<int> s;
    stack<int> builtStack(TreeNode* root){
        if(root!=NULL){
            s.push(root->val);
            builtStack(root->left);
            builtStack(root->right);
        }
        return s;
    }
    void flatten(TreeNode* root) {
        builtStack(root);
       stack<int> rs;
        while(!s.empty()){
            rs.push(s.top());
            s.pop();
        }
        rs.pop();
        while(!rs.empty() && root){
            root->left=NULL;
            root->right=new TreeNode(rs.top());
            root=root->right;
            rs.pop();
        }
    }
};