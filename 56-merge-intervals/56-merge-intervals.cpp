class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       int res=0;
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[res][1]>=intervals[i][0]){
                intervals[res][0]=min(intervals[res][0],intervals[i][0]);
                intervals[res][1]=max(intervals[res][1],intervals[i][1]);
            }
            else{
                res++;
                intervals[res]=intervals[i];
            }
        }
        for(int i=0;i<=res;i++){
            ans.push_back(intervals[i]);
        }
        return ans;
        
    }
};