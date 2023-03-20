class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        if(n==0)
        return true;
        if(n>nums.size())
            return false;
        
        if(nums.size()==1){
            
            if(nums[0]==0)
            return true;
            
            return false;
            
        }
        
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
            if(i==0){
                if(nums[i+1]==0){
                    nums[i]=1;
                    n--;
                }
            }
            else if(i==nums.size()-1){
                if(nums[i-1]==0){
                     nums[i]=1;
                    n--;
                }
            }
            else if( i>0 && i<nums.size()-1){
                if(nums[i+1]==0 && nums[i-1]==0){
                     nums[i]=1;
                    n--;
                }
            }
            }
        }
        return(n<=0);
    }
};