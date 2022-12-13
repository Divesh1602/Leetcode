class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        unordered_map<char,int> cs,cp;
        for(int i=0;i<s1.length();i++){
            cs[s2[i]]++;
            cp[s1[i]]++;
}
        for(int i=s1.length();i<s2.length();i++){
            if(cs==cp)
                return true;
            cs[s2[i]]++;
            cs[s2[i-s1.length()]]--;
            if(cs[s2[i-s1.length()]]==0)
                cs.erase(s2[i-s1.length()]);
        }
        if(cs==cp)
            return true;
        return false;
        
    }
};