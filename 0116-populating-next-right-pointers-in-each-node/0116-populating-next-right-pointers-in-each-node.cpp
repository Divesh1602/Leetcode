/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==nullptr){
            return nullptr;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto x=q.front();
                q.pop();
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
                if(n==0 or q.size()==0){
                    x->next=nullptr;
                }
                else{
                    x->next=q.front();
                }
            }
        }
        return root;
        
    }
};