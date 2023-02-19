class Solution {
public:
    void helper(vector<string>& ans,int open,int close,string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        
        if(open==close){
            op+='(';
            helper(ans,open-1,close,op);
        }
        else if(open==0){
            op+=')';
           helper(ans,open,close-1,op);
                       
        }
        else{
            string op1=op+'(';
            string op2=op+')';
            helper(ans,open-1,close,op1);
            helper(ans,open,close-1,op2);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,n,n,"");
        return ans;
    }
};