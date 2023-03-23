//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      Node* find(Node* root,int t,int& sum){
          if(!root)
          return NULL;
          
          if(root->data==t)
          return root;
          
         
          sum+=root->data;
          if(root->data<t)
          return find(root->right,t,sum);
          if(root->data>t)
         return find(root->left,t,sum);
          
          
          
      }
      void findSum(Node* root,int sum,int& ans){
          if(!root)
          return;
          if(!root->left && !root->right)
          {
              sum+=root->data;
        //   cout<<sum<<" ";
              ans=min(sum,ans);
              return;
          }
        //   cout<<root->data<<" ";
          sum+=root->data;
          findSum(root->left,sum,ans);
          findSum(root->right,sum,ans);
          sum-=root->data;
          return;
      }
    int maxDifferenceBST(Node *root,int target){
        int sum=0;
       Node* curr=find(root,target,sum);
       
       if(curr==NULL)
       return -1;
       
       int sum1=INT_MAX;
       findSum(curr,0,sum1);
    //   cout<<sum1<<" ";
      sum1-=curr->data;
       return sum-sum1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends