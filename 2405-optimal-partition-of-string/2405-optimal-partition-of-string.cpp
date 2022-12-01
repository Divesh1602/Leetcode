class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> m;
        int ct=0;
        for(int i=0;i<=s.length();i++){
            if(m.find(s[i])==m.end())
                m.insert(s[i]);
            else{
                ct++;
                m.clear();
                m.insert(s[i]);
            }
        }
        
            ct++;
        return ct;
    }
};