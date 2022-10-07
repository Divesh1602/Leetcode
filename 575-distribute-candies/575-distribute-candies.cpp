class Solution {
public:
    int distributeCandies(vector<int>& a) {
       unordered_set<int> s;
        for(auto i:a)
            s.insert(i);
        return min(s.size(),a.size()/2);
    }
};