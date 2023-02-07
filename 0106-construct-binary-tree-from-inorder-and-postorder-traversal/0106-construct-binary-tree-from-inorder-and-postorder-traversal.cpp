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
       int postIndex=0;
    TreeNode* BuildingTree(vector<int>& post,  unordered_map<int,int> &m,int st,int en){
        if(st>en)
            return NULL;
        TreeNode* root=new TreeNode(post[postIndex++]);
        
         int val=root->val;
        int index=m[val];
        
        root->right=BuildingTree(post,m,index+1,en);
        root->left=BuildingTree(post,m,st,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        reverse(postorder.begin(),postorder.end());
         return BuildingTree(postorder,m,0,postorder.size()-1);
    }
};