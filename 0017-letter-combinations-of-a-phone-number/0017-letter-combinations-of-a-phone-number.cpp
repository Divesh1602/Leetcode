class Solution {
public:
      string m[10] = {""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string s,vector<string>& ans,int i,string op){
        if(i==s.length()){
           
            ans.push_back(op);
            return;
        }
        string find=m[s[i]-'0'];
       
        for(int k=0;k<find.length();k++){
            string op1=op+find[k];
            helper(s,ans,i+1,op1);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
       vector<string> ans;
       if(digits.length()>0)        
        helper(digits,ans,0,"");
        
        return ans;
    }
};