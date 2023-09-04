class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int> m,mp;
        for(int i=0;i<s1.length();i++){
            if(i%2==0)
           m[s1[i]]++;
            else
                mp[s1[i]]++;
        }
        for(int i=0;i<s2.length();i++){
            if(i%2==0)
            {
                if(m.find(s2[i])!=m.end()){
                    m[s2[i]]--;
                    if(m[s2[i]]==0)
                        m.erase(s2[i]);
                }
            }
            else{
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]--;
                    if(mp[s2[i]]==0)
                        mp.erase(s2[i]);
                }
            }
        }
        if(m.empty() && mp.empty())
            return true;
        return false;
    }
};