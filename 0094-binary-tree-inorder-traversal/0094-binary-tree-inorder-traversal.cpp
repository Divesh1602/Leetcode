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
   vector<int>v;
   vector<int> traverseInorder(TreeNode *temp){
	if(temp){
		traverseInorder(temp->left);
		v.push_back(temp->val);
		traverseInorder(temp->right);
	}
    return v;
}
    vector<int> inorderTraversal(TreeNode* root) {
        return traverseInorder(root);
    }
};