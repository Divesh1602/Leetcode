class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int sum) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        vector<int> a=nums;
        while(i<j){
            if(nums[i]+nums[j]==sum)
                break;
            if(nums[i]+nums[j]<sum)
                i++;
            else
                j--;
        }
        
        int b;
        for(int k=0;k<a.size();k++){
            if(a[k]==nums[i]){
                ans.push_back(k+1);
                b=k;
                break;
            }
                
        }
        for(int k=0;k<a.size();k++){
            if(a[k]==nums[j] && k!=b){
                ans.push_back(k+1);
                b=k+1;
                break;
            }
        }
        return ans;
    }
};