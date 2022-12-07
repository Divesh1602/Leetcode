class Solution {
public:
    int numDifferentIntegers(string word) {
       unordered_set<string> res;
        for(int i=0;i<word.length();i++){
            if(isdigit(word[i])==true){
                while(word[i]=='0')
                    i++;
                string ans="";
                while(isdigit(word[i])==true){
                    ans+=word[i];
                    i++;
                }
                res.insert(ans);
            }
        }
        
        return res.size();
    }
};