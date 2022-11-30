class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto a:arr)
            m[a]++;
    
    // multimap<int,int> m1;
    // for(auto a:m){
    //     m1.insert({a.second,a.first});
    // }
    //    int x=m1.begin()->first;
    //    int c=0;
    // for(auto a:m1){
    //     if(a.first==x && c==1)
    //         return false;
    //     x=a.first;
    //     c=1;
    // }
    //  return true;   
    // }
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