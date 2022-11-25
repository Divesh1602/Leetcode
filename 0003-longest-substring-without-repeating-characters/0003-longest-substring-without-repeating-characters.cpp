class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res=0;
        for(int i=0;i<s.length();i++){
            unordered_set<char> ans;
            int ct=0;
           for(int j=i;j<s.length();j++){
               
               if(ans.find(s[j])==ans.end())
                   ans.insert(s[j]);
               else
               {  
                   break;
               }
               ct++;
           }
            res=max(res,ct);
            }
        return res;
        
    }
};