class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        list<int> l;
        int i=0,j=0;
        int ans=0;
        int ct=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                l.push_back(j);
                ct++;
            }
            if(ct>k){
                while(ct>k){
                    if(nums[i]%2!=0)
                    {
                         l.pop_front();
                        ct--;
                       
                    }
                    i++;
                }
            }
            if(ct==k){
               int st=l.front();
                ans+=st-i+1;
            }
            j++;
        }
        return ans;
    }
};