class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans=0;
        int st=INT_MIN;
        for(int i=0;i<pairs.size();i++){
            if(st<pairs[i][0]){
                st=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};