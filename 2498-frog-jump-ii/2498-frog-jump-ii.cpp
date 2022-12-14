class Solution {
public:
    int maxJump(vector<int>& stones) {
        if(stones.size()==2)
            return max(stones[0],stones[1]);
        int ans=0;
        int ans1=0;
        for(int i=2;i<stones.size();i+=2)
            ans=max(ans,stones[i]-stones[i-2]);
        for(int i=3;i<stones.size();i+=2)
            ans1=max(ans1,stones[i]-stones[i-2]);
        return max(ans,ans1);
    }
};