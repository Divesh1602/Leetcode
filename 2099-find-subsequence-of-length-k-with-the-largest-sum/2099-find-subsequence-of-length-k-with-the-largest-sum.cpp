class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        vector<int> v=nums;
       sort(v.begin(),v.end());
        for(int i=v.size()-k;i<v.size();i++){
        
            m[v[i]]++;
           
        }
        for(auto a:nums){
            if(m[a]>0){
                ans.push_back(a);
                m[a]--;
                if(m[a]==0)
                    m.erase(a);
            }
        }
        return ans;
    }
};