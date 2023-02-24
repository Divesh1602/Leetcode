class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,ans,path);
        return ans;
    }
    void helper(int idx,string s,vector<vector<string>>& ans,vector<string> path){
        if(idx==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPossible(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,ans,path);
                path.pop_back();
            }
        }
        return;
    }
    bool isPossible(string s,int st,int en){
        while(st<=en){
            if(s[st++]!=s[en--])
                return false;
        }
        return true;
    }
};