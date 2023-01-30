class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> s1,s2,temp;
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!s2.empty() && nums[s2.top()]<nums[i])
            {
                ans[s2.top()]=nums[i];
                s2.pop();
            }
            while(!s1.empty() && nums[s1.top()]<nums[i]){
                temp.push(s1.top());
                s1.pop();
            }
            while(!temp.empty()){
                s2.push(temp.top());
                temp.pop();
            }
            s1.push(i);
        }
        return ans;
    }
};