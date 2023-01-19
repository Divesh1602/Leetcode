class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
           return intersect(nums2,nums1);
           
        }
       multiset<int> s;
        multiset<int> s1;
       for(int i=0;i<nums1.size();i++){
           s.insert(nums1[i]);
       }
       for(int i=0;i<nums2.size();i++){
            s1.insert(nums2[i]);
       }
       vector<int> ans;
       for(auto x:s){
           auto it=s1.find(x);
           if(it!=s1.end()){
           ans.push_back(x);
           s1.erase(it);
           }
       }
       return ans;
    }
};