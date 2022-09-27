class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> a(nums.size()-1);
        for(int i=0;i<nums.size();i++){
            if(a[nums[i]])
                return nums[i];
            a[nums[i]]=true;
        }
        return 0;
    }
};