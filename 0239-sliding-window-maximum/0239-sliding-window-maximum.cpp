class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int i=0,j=0;
       
        while(j<nums.size()){
            if(j-i+1<k){
                while(!dq.empty() && dq.back()<nums[j])
                    dq.pop_back();
                dq.push_back(nums[j]);
                j++;
            }
            else{
                while(!dq.empty() && dq.back()<nums[j])
                    dq.pop_back();
                dq.push_back(nums[j]);
                ans.push_back(dq.front());
                if(dq.front()==nums[i])
                    dq.pop_front();
                i++;
                
                j++;
            }
        }
        return ans;
    }
};