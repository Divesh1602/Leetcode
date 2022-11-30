class Solution {
public:
    int characterReplacement(string s, int k) {
       int i=0;
        unordered_map<int,int> m;
        int mx=INT_MIN;
        int res=INT_MIN;
        for(int j=0;j<s.length();j++){
            m[s[j]]++;
            mx=max(mx,m[s[j]]);
            if(j-i+1-mx>k){
                m[s[i]]--;
                    i++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};