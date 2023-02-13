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
   
    TreeNode* constructTree(vector<int>& nums,int i,int j){
        if(i>j)
            return NULL;
        int idx;
        int ele=INT_MIN;
        for(int k=i;k<=j;k++){
            if(ele<nums[k]){
                ele=nums[k];
                idx=k;
            }
        }
        TreeNode* root=new TreeNode(ele);
        root->left=constructTree(nums,i,idx-1);
        root->right=constructTree(nums,idx+1,j);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      
        return constructTree(nums,0,nums.size()-1);
    }
};