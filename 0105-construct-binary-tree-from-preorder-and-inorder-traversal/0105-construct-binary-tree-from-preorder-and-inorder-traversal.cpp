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
    int preIndex=0;
    TreeNode* BuildingTree(vector<int>& pre, unordered_map<int,int> &m,int st,int en){
        if(st>en)
            return NULL;
        TreeNode* root=new TreeNode(pre[preIndex++]);
        
        int val=root->val;
        int index=m[val];
        
        
        
        root->left=BuildingTree(pre,m,st,index-1);
        root->right=BuildingTree(pre,m,index+1,en);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return BuildingTree(preorder,m,0,preorder.size()-1);
    }
};