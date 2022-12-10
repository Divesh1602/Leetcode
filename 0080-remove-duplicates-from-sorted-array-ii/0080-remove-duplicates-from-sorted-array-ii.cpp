class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int check=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i])
            {
                i++;
                nums[i]=nums[j];
                check=0;
            }
            else if(nums[i]==nums[j] && check==0){
                i++;
                nums[i]=nums[j];
                check=1;
            }
        }
        return i+1;
    }
};