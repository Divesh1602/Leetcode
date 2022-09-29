class Solution {
public:
    bool isfeasible(vector<int> A,long long k,int ans){
        int sum=0;
        for(auto a:A){
            k-=a/ans;
            }
         if(k<=0)
                return true;
         return false;
        }
       
    
    int maximumCandies(vector<int>& candies, long long k) {
        int i=1;
       long long int j=0;
        int res=0;
        for(auto a:candies){
            j+=a;
        }
        while(i<=j){
           long long int mid=(i+j)/2;
            if(isfeasible(candies,k,mid)){
                res=mid;
                i=mid+1;
            }
            else
                j=mid-1;
        }
        return res;
    }
};