class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> v;
        string res;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                v.push_back(res.length());
            else if(s[i]==')'){
                int index=v.back();
                v.pop_back();
                reverse(res.begin()+index,res.end());
            }
            else
                res+=s[i];
        }
        return res;
        
    }
};