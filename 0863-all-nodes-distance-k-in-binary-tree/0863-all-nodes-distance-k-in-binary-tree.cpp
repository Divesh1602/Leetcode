/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void traverse(TreeNode *a,vector<vector<int>>&adj){
    if(a==NULL){
        return ;
    }
    if(a->left!=NULL){
        adj[a->val].push_back(a->left->val);
        adj[a->left->val].push_back(a->val);
    }
    if(a->right!=NULL){
        adj[a->val].push_back(a->right->val);
        adj[a->right->val].push_back(a->val);
    }
    traverse(a->left,adj);
    traverse(a->right,adj);
}
void dfs(vector<int>&ans,vector<vector<int>>&adj,int n,int val,int k, vector<int>&vis){
    if(n==k){
        ans.push_back(val);
        return ;
    }
    vis[val]=1;
    for(auto j:adj[val]){
        if(vis[j]==0){
            dfs(ans,adj,n+1,j,k,vis);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    
      vector<vector<int>>adj(501);
      traverse(root,adj);
      vector<int>ans;
      vector<int>vis(501,0);
      dfs(ans,adj,0,target->val,k,vis);



      return ans;
    }
};