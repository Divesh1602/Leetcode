class Solution {
public:
    const int CHAR=256;
    int firstUniqChar(string s) {
       unordered_map<char,int> store;
        for(int i=0;i<s.length();i++)
            store[s[i]]++;
        for(int i=0;i<s.length();i++){
            if(store[s[i]]==1)
                return i;
        }
        return -1;
    }
};