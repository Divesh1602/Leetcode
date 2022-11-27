class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int ct=0;
        for(int j=0;j<s.length();j++){
           if(s[j]==t[i]){
               i++;
               ct++;
           }
            
        }
        return (t.length()-ct);
    }
};