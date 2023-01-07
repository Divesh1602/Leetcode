class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     
        int gsum=0,csum=0;
        int ans=0;
       int sum=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                ans=i+1;
            sum=0;
            }
            gsum+=gas[i],csum+=cost[i];
        }
        if(gsum<csum)
            return -1;
        return ans;
    }
};   