class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        unordered_set<int> s;
        
      
        
        int al=0,bb=0;
        for(int i=0;i<aliceSizes.size();i++){
            al+=aliceSizes[i];
            s.insert(aliceSizes[i]);
        }
        for(int i=0;i<bobSizes.size();i++){
            bb+=bobSizes[i];
        }
        int value=(al-bb)/2;
        for(int i=0;i<bobSizes.size();i++){
          int a=value + bobSizes[i];
           auto pos=s.find(a);
            if(pos!=s.end()){
                ans.push_back(a);
                ans.push_back(bobSizes[i]);
                return ans;
            }
            
        }
        return ans;
    }
};