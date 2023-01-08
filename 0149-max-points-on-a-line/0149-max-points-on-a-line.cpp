class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
       
        for(int i=0;i<points.size();i++){
             unordered_map<float,int> m;
            for(int j=i+1;j<points.size();j++){
                if(points[j][0]==points[i][0])
                    m[INT_MAX]++;
                else{
                    float slope=(float)(points[j][1]-points[i][1])/(float)(points[j][0]-points[i][0]);
                    m[slope]++;
                }
            }
            int mx=0;
            for(auto a:m){
                mx=max(mx,a.second);
               
            }
            mx++;
            ans=max(mx,ans);
        }
        return ans;
    }
};