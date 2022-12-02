class Solution {
public:
    bool closeStrings(string word1, string word2) {
       unordered_map<char,int> mw1;
        unordered_map<char,int> mw2;
        set<int> slw1,slw2;
        multiset<int> sfw1,sfw2;
        for(auto a:word1)
        {
            slw1.insert(a);
            mw1[a]++;
        }
        for(auto a:word2)
        {
            slw2.insert(a);
            mw2[a]++;
        }
        for(auto a:mw1)
            sfw1.insert(a.second);
         for(auto a:mw2)
            sfw2.insert(a.second);
        return  slw1==slw2 && sfw1==sfw2;
    }
};