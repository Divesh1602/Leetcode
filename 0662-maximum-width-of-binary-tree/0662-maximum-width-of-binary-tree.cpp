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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans=1;
    while(!q.empty()){
        int st=q.front().second;
        int en=q.back().second;
        int cnt=q.size();
        ans=max(ans,en-st+1);
        for(int i=0;i<cnt;i++){
            pair<TreeNode*,long long> p=q.front();
            q.pop();
            int idx=p.second-st;
            if(p.first->left!=NULL){
                q.push({p.first->left,(long long)2*idx+1});
            }
            if(p.first->right!=NULL){
                q.push({p.first->right,(long long)2*idx+2});
            }
        }
    }
        return ans;
    }
};