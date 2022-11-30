class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto a:arr)
            m[a]++;
        unordered_set<int> s;
        for(auto a:m){
            if(s.find(a.second)==s.end())
                s.insert(a.second);
                else 
                    return false;
        }
           return true;  
    }
};