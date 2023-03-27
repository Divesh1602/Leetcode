class Solution {
public:
    int getLoopLen(int start, vector<int>& edges, vector<bool>& isTraversed) {
        int pre = start;
        int post = edges[pre];
        if (post < 0) {
            return -1;
        }
        post = edges[post];
        while (pre != post) {
            if (isTraversed[pre]) {
                return -1;
            }
            isTraversed[pre] = true;
            pre = edges[pre];
            if (post < 0) {
                return -1;
            }
            post = edges[post];
            if (post < 0) {
                return -1;
            }
            post = edges[post];
        }
        int ret = 1;
        int index = edges[post];
        while (index != post) {
            ret++;
            index = edges[index];
        }
        return ret;
    }
    int longestCycle(vector<int>& edges) {
        vector<bool> isTraversed(edges.size(), false);
        int ans = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (!isTraversed[i]) {
                ans = max(ans, getLoopLen(i, edges, isTraversed));
            }
        }
        return ans;
    }
};