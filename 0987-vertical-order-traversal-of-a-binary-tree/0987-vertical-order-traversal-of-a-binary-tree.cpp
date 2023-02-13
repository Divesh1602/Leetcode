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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            unordered_map<int,vector<int>> m1;
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*,int> p=q.front();
                q.pop();
                int hd=p.second;
                m1[hd].push_back(p.first->val);
                if(p.first->left)
                    q.push({p.first->left,hd-1});
                if(p.first->right)
                    q.push({p.first->right,hd+1});
            }
            for(auto a:m1){
                int hd=a.first;
                vector<int> v=a.second;
                sort(v.begin(),v.end());
                for(auto c:v){
                    m[hd].push_back(c);
                }
            }
            
        }
        vector<vector<int>> ans;
        for(auto a:m){
            ans.push_back(a.second);
        }
        return ans;
    }
};