class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(nums[i]==val) nums.erase(nums.begin()+i);
            else i++;
            j++;
        }
        return nums.size();
    }
};