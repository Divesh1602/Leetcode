class Solution {
public:
    bool  isValid(int mid,vector<int>& weights,int days){
        int k=1;
        int sum=0;
        for(auto a:weights){
            if(a>mid)
                return 0;
            if(sum+a>mid){
                k++;
                sum=0;
            }
            sum+=a;
        }
      
        return (k<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
       
       
        int i=1;
        int j=INT_MAX;
        int ans;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(isValid(mid,weights,days)){
                
                ans=mid;
              
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};