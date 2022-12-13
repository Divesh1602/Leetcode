class Solution {
public:
    // bool issame(int cs[],int cp[]){
    //     for(int i=0;i<256;i++)
    //         if(cs[i]!=cp[i])
    //             return false;
    //     return true;
    // }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length())
            return ans;
       unordered_map<char,int> cs,cp;
        for(int i=0;i<p.length();i++){
            cs[s[i]]++;
            cp[p[i]]++;
           
        }
        for(int i=p.length();i<s.length();i++){
            if(cs==cp){
                ans.push_back(i-p.length());
            }
            cs[s[i]]++;
           
            cs[s[i-p.length()]]--;
             if(cs[s[i-p.length()]]==0)
                 cs.erase(s[i-p.length()]);
            
        }
          if(cs==cp){
                ans.push_back(s.length()-p.length());
            }
        return ans;
    }
};