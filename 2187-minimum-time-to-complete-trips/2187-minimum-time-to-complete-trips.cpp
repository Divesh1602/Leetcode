class Solution {
public:
    long long isValid(long long mid,vector<int>& time,int k){
        long long ct=0;
        for(int i=0;i<time.size();i++){
            ct+=mid/time[i];
        }
        return (ct>=k);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long i=1;
        long long j=(long long)time[0]*totalTrips;
        long long ans=0;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(isValid(mid,time,totalTrips))
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};