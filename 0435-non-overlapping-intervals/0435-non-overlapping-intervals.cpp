class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int pt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[pt][1]>intervals[i][0]){
                intervals[pt][0]=max(intervals[pt][0],intervals[i][0]);
                intervals[pt][1]=min(intervals[pt][1],intervals[i][1]);
                ans++;
            }
            else{
                pt++;
                intervals[pt]=intervals[i];
            }
        }
        return ans;
    }
};