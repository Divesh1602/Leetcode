class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1){
            if(gas[0]<cost[0])
                return -1;
            return 0;
        }
        int sum=0,sum1=0;
        for(int i=0;i<gas.size();i++)
            sum+=gas[i],sum1+=cost[i];
        
        if(sum<sum1)
            return -1;
        
        int ans=-1;
        sum=0;
        for(int i=0;i<gas.size();i++){
            sum=sum+gas[i]-cost[i];
            if(sum>0)
            {
                ans=i;
                i++;
                while(sum>0 && i<gas.size()){
                   
                    sum+=gas[i]-cost[i];
                     i++;
                }
                if(sum<0){
                    sum=0;
                    ans=-1;
                }
              i--;
            }
            else if(sum<0){
                sum=0;
                ans=-1;
            }
            
        }
        return ans;
    }
};   