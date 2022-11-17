class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m;
        for(auto a:words1)
            m[a]++;
        unordered_map<string,int> m1;
        for(auto a:words2)
            m1[a]++;
        int ct=0;
        for(string word:words1){
            if(m[word]==1 && m1[word]==1)
                ct++;

    }
        return ct;
    }
};