class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> m1,m2;
        for(char ch:word1)
            m1[ch]++;
        for(char ch:word2)
            m2[ch]++;
        
        for(auto a1 : m1){
            char ch=a1.first;
            for(auto a2 : m2){
                char c=a2.first;
                unordered_map<char,int> w1=m1,w2=m2;
                w1[c]++;
                w2[ch]++;
                
                w1[ch]--;
                w2[c]--;
                if(w1[ch]==0)
                    w1.erase(ch);
                if(w2[c]==0)
                    w2.erase(c);
                if(w1.size()==w2.size())
                    return true;
            }
        }
        return false;
    }
};