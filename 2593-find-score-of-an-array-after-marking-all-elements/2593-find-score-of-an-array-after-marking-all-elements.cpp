class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        long long ans=0;
        unordered_set<int> s;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(s.find(v[i].second)==s.end()){
                ans+=v[i].first;
                s.insert(v[i].second);
                s.insert(v[i].second+1);
                s.insert(v[i].second-1);
            }
        }
        return ans;
    }
};