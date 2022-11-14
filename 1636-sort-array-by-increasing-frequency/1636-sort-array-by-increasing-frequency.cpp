class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
          map<int,int> m;
        for(auto a:nums)
            m[a]++;
   
    multimap<int,int> m1;
    for(auto it=m.rbegin();it!=m.rend();it++){
        m1.insert({it->second,it->first});
    }
   
        vector<int> res;
    for(auto a:m1){
        int ocu=a.first;
        for(int i=0;i<ocu;i++){
        res.push_back(a.second);
        }
    }
   
        return res;
       
    }
};