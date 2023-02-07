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
    TreeNode* BuildingTree(vector<int>& post, vector<int>& in,int st,int en){
        if(st>en)
            return NULL;
        TreeNode* root=new TreeNode(post[postIndex++]);
        
        int index;
        for(int i=st;i<=en;i++){
            if(in[i]==root->val){
                index=i;
                break;
            }
        }
        
        root->right=BuildingTree(post,in,index+1,en);
        root->left=BuildingTree(post,in,st,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
         return BuildingTree(postorder,inorder,0,postorder.size()-1);
    }
};