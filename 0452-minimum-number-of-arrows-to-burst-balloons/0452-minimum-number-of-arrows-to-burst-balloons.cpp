class Solution {
public:
   static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        // for(auto a:points)
        //     cout<<a[0]<<" "<<a[1]<<endl;
        int ans=1;
        int st=points[0][1];
        for(auto a:points){
            if(a[0]<=st && a[1]>=st){
                continue;
            }
            else{
                ans++;
                st=a[1];
            }
        }
        return ans;
    }
};