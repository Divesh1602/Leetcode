class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ct=0,sum=0;
        for(auto a : costs){
            sum+=a;
            if(sum>coins)
                return ct;
            ct++;
        }
        return ct;
    }
};