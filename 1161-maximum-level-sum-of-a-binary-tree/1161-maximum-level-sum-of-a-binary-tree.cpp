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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int mx=root->val;
        int ans=1;
        int level=1;
        while(!q.empty()){
            
            int sum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    sum+=curr->left->val;
                }
                if(curr->right){
                    q.push(curr->right);
                    sum+=curr->right->val;
                }
            }
            if(!q.empty())
                level++;
            if(mx<sum){
                mx=sum;
                ans=level;
            }
        }
        
        return ans;
    }
};