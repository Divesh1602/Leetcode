class Solution {
public:
    void helper(string& s,vector<string>& ans,string op,int i){
        if(i==s.length()){
            ans.push_back(op);
            return;
        }
        if(s[i]>='a' && s[i]<='z'){
            string op1=op;
            op1+=s[i];
            string op2=op;
            op2+=toupper(s[i]);
            helper(s,ans,op1,i+1);
             helper(s,ans,op2,i+1);
        }
        else if(s[i]>='A' && s[i]<='Z'){
            string op1=op;
            op1+=s[i];
            string op2=op;
            op2+=tolower(s[i]);
            helper(s,ans,op1,i+1);
             helper(s,ans,op2,i+1);
        }
        else{
            helper(s,ans,op+s[i],i+1);
             }
        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(s,ans,"",0);
        return ans;
    }
};