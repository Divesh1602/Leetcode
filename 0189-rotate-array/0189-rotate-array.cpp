class Solution {
public:
    void rev(vector<int>& nums,int i,int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
        return;
    
    }
};