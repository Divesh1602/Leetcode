class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int,int> m;
        int ans=0;
        for(auto a:nums)
            m[a]++;
        for(int i=0;i<nums.size();i++){
            auto it=m.upper_bound(nums[i]);
            if(it==m.end()){
                auto it1=m.begin();
                (*it1).second--;
                if((*it1).second==0)
                    m.erase((*it1).first);
            }
            else{
                ans++;
                (*it).second--;
                if((*it).second==0)
                    m.erase((*it).first);
            }
        }
        return ans;
    }
};