class Solution {
public:
 bool isValid(long long mid,vector<int> ranks,int cars){
     long long ct=0;
     for(int i=0;i<ranks.size();i++){
         long long cal=(long long)mid/(long long)ranks[i];
         ct+=sqrt(cal);
     }
     return(ct>=cars);
 }
    long long repairCars(vector<int>& ranks, int cars) {
        long long i=1,j=LLONG_MAX,ans=0;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(isValid(mid,ranks,cars)){
                j=mid-1;
                ans=mid;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};