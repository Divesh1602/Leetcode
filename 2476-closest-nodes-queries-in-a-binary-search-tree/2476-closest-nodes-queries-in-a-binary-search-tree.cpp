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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
        
    }
    
    
     
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        int n=v.size();
        
        vector<vector<int>>ans;
        
     for(auto a:queries){
              int mn=-1,mx=-1;
             int l=0,h=n-1;
        while(l<=h){
           int mid=l+(h-l)/2;
           if(v[mid]==a){
               mn=a;
               mx=a;
              break;
           }
           if(v[mid]>a){
               mx=v[mid];
              h=mid-1;
           }
           else{
               mn=v[mid];
             l=mid+1;
           }
       }
             ans.push_back({mn,mx});
    }
        return ans;
    }
};

