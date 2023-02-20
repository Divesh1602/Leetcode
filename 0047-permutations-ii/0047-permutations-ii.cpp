class Solution {
public:
       void solution(set<vector<int>>&ans,vector<int>&nums,int index){
    if (index==nums.size())
    {
        ans.insert(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index],nums[i]);
        solution(ans,nums,index+1);
        swap(nums[i],nums[index]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
         set<vector<int>>ans;
    int index=0;
    solution(ans,nums,index);
        vector<vector<int>> v;
        for(auto a:ans)
            v.push_back(a);
    return v;
    }
};