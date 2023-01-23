class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         unordered_map<int,int> m;
        if(n == 1) return 1;
        for(int i = 0;i<trust.size();i++)
        {
            m[trust[i][0]] = INT_MIN;
            m[trust[i][1]]++;
        }
        for(auto i : m)
        {
            if(i.second == n-1) return i.first;
        }
        return -1;
    }
};