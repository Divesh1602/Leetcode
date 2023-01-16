class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        for(auto a:intervals){
            temp.push_back(a);
        }
        
            temp.push_back(newInterval);
        int res=0;
        sort(temp.begin(),temp.end());
        for(int i=1;i<temp.size();i++){
            if(temp[i][0]>=temp[res][0] && temp[i][0]<=temp[res][1]){
                temp[res][0]=min(temp[res][0],temp[i][0]);
                temp[res][1]=max(temp[res][1],temp[i][1]);
                
            }
            else{
                res++;
                temp[res]=temp[i];
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<=res;i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};