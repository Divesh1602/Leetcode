class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mx=INT_MIN;
        int sum=0;
        int res=0;
        for(int i=0;i<neededTime.size()-1;i++){
            sum=0;
            mx=INT_MIN;
           while(colors[i]==colors[i+1]){
              mx=max(mx,neededTime[i]);
               sum+=neededTime[i];
               i++;
               
           }
             mx=max(mx,neededTime[i]);
            sum+=neededTime[i];
            sum=sum-mx;
            res+=sum;
        }
        return res;
    }
};