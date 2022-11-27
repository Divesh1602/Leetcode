class Solution {
public:
    int find(vector<int> nums, int k){
        int i=0;
        int res=0;
        unordered_map<int,int> m;
        for(int j=0;j<nums.size();j++){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            res+=j-i+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return find(nums,k)-find(nums,k-1);
    }
};