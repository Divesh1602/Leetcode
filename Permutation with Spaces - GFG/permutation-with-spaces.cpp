//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void helper(string s,vector<string>& ans,int i,string op){
        if(s.length()==i)
        {
            ans.push_back(op);
            return;
        }
        string op1=op+s[i];
        helper(s,ans,i+1,op1);
       string op2=op+" "+s[i]; 
        helper(s,ans,i+1,op2);
        return;
        
    }
    vector<string> permutation(string s){
        // Code Here
        vector<string> ans;
        string op="";
        op+=s[0];
        helper(s,ans,1,op);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends