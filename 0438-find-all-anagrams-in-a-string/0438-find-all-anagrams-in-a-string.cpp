class Solution {
public:
    bool issame(int cs[],int cp[]){
        for(int i=0;i<256;i++)
            if(cs[i]!=cp[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length())
            return ans;
        int cs[256]={0},cp[256]={0};
        for(int i=0;i<p.length();i++){
            cs[s[i]]++;
            cp[p[i]]++;
           
        }
        for(int i=p.length();i<s.length();i++){
            if(issame(cs,cp)){
                ans.push_back(i-p.length());
            }
            cs[s[i]]++;
            cs[s[i-p.length()]]--;
            
        }
          if(issame(cs,cp)){
                ans.push_back(s.length()-p.length());
            }
        return ans;
    }
};