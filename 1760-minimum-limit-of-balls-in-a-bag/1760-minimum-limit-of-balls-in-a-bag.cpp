class Solution {
public:
    bool isvalid(vector<int> a,int k,int mid,int n){
        for(int i=0;i<n;i++){
           
             
              if(a[i]%mid==0){
                  int cal=(a[i]/mid)-1;
                  k-=cal;
              }
               else{
                    int cal=(a[i]/mid);
                   k-=cal;
               }
           
        }
        return(k>=0);
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=1,j=nums[n-1];
        int  ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(isvalid(nums,maxOperations,mid,n)){
                ans=mid;
                // cout<<ans<<" ";
                j=mid-1;
            }
            else 
                i=mid+1;
        }
        return ans;
    }
};