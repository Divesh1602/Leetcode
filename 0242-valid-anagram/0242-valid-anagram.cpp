class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
           m[s[i]]++;
        }
        // if(s.length()!=m.size())
        //     return false;
        
        for(int i=0;i<t.length();i++){
           m[t[i]]--;
        }
        for(auto a:m){
            if(a.second!=0)
                return false;
        }
        return true;
    }
};