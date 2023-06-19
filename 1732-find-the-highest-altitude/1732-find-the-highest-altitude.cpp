class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x=0;
        int ans=0;
        for(auto a:gain){
            x+=a;
            ans=max(ans,x);
            
            }
        return ans;
    }
};