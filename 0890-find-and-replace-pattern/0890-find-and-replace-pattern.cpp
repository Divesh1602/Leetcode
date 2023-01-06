class Solution {
public:
    bool ispossible(string str1,string str2){
        unordered_map<char,char> m;
        vector<bool> v(26,false);
        for(int i=0;i<str1.length();i++){
            char ch1=str1[i],ch2=str2[i];
            if(m[ch1] && m[ch1]!=ch2)
                return false;
            if(!m[ch1] && v[ch2 - 'a'])
                return false;
            m[ch1]=ch2;
            v[ch2-'a']=true;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string str: words){
            if(ispossible(str,pattern))
                ans.push_back(str);
        }
        return ans;
    }
};