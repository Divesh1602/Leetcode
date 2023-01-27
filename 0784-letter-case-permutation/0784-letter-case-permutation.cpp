class Solution {
public:
void helper(string s ,int i, int n , vector<string> &ans){

    if(i == n){
        ans.push_back(s);
        return;
    }

    if(s[i] >= 'a' && s[i] <= 'z'){
        string temp = s.substr(0,i) + char(s[i] - 32) + s.substr(i+1);
		
        helper(s,i+1,n,ans);
        helper(temp,i+1,n,ans);
    }
    else if(s[i] >= 'A' && s[i] <= 'Z'){
        string temp = s.substr(0,i) + char(s[i] + 32) + s.substr(i+1);
		
        helper(s,i+1,n,ans);
        helper(temp,i+1,n,ans);
    }
    else{
        helper(s,i+1,n,ans);
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> ans;

    helper(s,0,s.length(),ans);

    return ans;
}
};