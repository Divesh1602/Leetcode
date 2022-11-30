class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream str(s);
        
        int i=0;
        
        unordered_map<char,int> mp;
        
        unordered_map<string,int> ms;
        
        int n=pattern.length();
        
        for(string word; str>>word;i++){
        
            if(i==n || mp[pattern[i]]!=ms[word])
            
                return false;
            
            mp[pattern[i]]=ms[word]=i+1;
        }
        
        return (i==n);
    }
};