class Solution {
public:
    bool isValid(int mid,int p,vector<int>& nums){
        int i=0;
        int j=1;
        int n=nums.size();
        int ct=0;
        while(i<n-1){
            if(abs(nums[i]-nums[i+1])<=mid){
                ct++;
                i+=2;
            }
           
            else
                i++;
            
        }
        return(ct>=p);
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int i=0,j=INT_MAX;
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(isValid(mid,p,nums)){
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};