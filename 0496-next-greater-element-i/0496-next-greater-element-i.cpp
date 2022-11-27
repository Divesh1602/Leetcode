class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i=0;i<nums1.size();i++){
            int ct=0;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                  
                    while(j<nums2.size()){
                        
                        if(nums2[j]>nums1[i]){
                            ct=1;
                             ans.push_back(nums2[j]);
                            break;
                        }
                        j++;
                    }
                }
            }
            if(ct==0)
                ans.push_back(-1);
            
               
        }
        return ans;
    }
};