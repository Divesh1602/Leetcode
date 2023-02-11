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
    
   int getHeight(TreeNode* root){
       if(root==NULL)
           return -1;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
    
    
    int balance(TreeNode* root){
        return getHeight(root->left)-getHeight(root->right);
    }
    
    
    
    TreeNode* leftrotate(TreeNode* root){
        TreeNode* temp=root->right;
        root->right=temp->left;
        temp->left=getRotation(root);
        return getRotation(temp);
    }
    
       
    TreeNode* rightrotate(TreeNode* root){
        TreeNode* temp=root->left;
        root->left=temp->right;
        temp->right=getRotation(root);
        return getRotation(temp);
    }
    
    TreeNode* getRotation(TreeNode* root){
        int h=balance(root);
        if(h>=2){
            if(balance(root->left)>=1){
                return rightrotate(root);
            }
            else{
                root->left=leftrotate(root->left);
                return rightrotate(root);
            }
        }
        else if(h<=-2){
            if(balance(root->right)<=-1){
                return leftrotate(root);
                
            }
            else{
                root->right=rightrotate(root->right);
                return leftrotate(root);
            }
            
        }
        return root;
        
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        root->left=balanceBST(root->left);
        
        root->right=balanceBST(root->right);
        
        
        return getRotation(root);
    }
};