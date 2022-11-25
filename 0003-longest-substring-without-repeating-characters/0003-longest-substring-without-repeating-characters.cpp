class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        unordered_set<char> ans;
        int ct=0;
        int res=0,i=0;
        for(int k=0;k<s.length();k++){
            if(ans.find(s[k])==ans.end())
                ans.insert(s[k]);
            else{
                while(ans.find(s[k])!=ans.end()){
                    ans.erase(s[i]);
                    i++;
                    ct--;
                }
                ans.insert(s[k]);
            }
            ct++;
            res=max(res,ct);
        }
        return res;
    }
};