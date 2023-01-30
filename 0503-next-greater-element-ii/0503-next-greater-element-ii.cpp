class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& temp) {
        vector<int> nums;
        for(auto a:temp){
            nums.push_back(a);
        }
        for(auto a:temp){
            nums.push_back(a);
        }
       stack<int> st;
        int n=nums.size();
        st.push(nums[n-1]);
        vector<int> ans;
        ans.push_back(-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            ans.push_back((st.empty())? -1:st.top());
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
       for(int i=0;i<n/2;i++)
           ans.pop_back();
        return ans;
    }
};