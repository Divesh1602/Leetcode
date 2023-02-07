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
    TreeNode* BuildingTree(vector<int>& pre, vector<int>& in,int st,int en){
        if(st>en)
            return NULL;
        TreeNode* root=new TreeNode(pre[preIndex++]);
        
        int index;
        for(int i=st;i<=en;i++){
            if(in[i]==root->val){
                index=i;
                break;
            }
        }
        
        root->left=BuildingTree(pre,in,st,index-1);
        root->right=BuildingTree(pre,in,index+1,en);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return BuildingTree(preorder,inorder,0,preorder.size()-1);
    }
};