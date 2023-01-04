class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        int ans=0;
        for(int a=0;a<m;a++){
            for(int i=1;i<n;i++){
                if(strs[i][a]<strs[i-1][a])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};