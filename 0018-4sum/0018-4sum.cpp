class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
              long long  ToFind = (long long)((long long)target-(long long)nums[i]-(long long)nums[j]);
                int x=j+1,y=nums.size()-1;
                while(x<y){
                    int sum=nums[x]+nums[y];
                    if(sum==ToFind){
                        s.insert({nums[i],nums[j],nums[x],nums[y]});
                        x++;
                        y--;
                    }
                    else if(sum>ToFind)
                        y--;
                    else
                        x++;
                }
            }
        }
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
};