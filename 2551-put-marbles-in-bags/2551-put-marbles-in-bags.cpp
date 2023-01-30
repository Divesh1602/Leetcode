class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        
        if(weights.size()==k)
            return 0;
        
        
        vector<int> v;
        
        
        for(int i=0;i<weights.size()-1;i++)
            
            v.push_back(weights[i]+weights[i+1]);
        
        
        sort(v.begin(),v.end());
        
        long long mn=0,mx=0;
        
        for(int i=0;i<k-1;i++)
            
            mn+=v[i];
        
        
        sort(v.rbegin(),v.rend());
        
        for(int i=0;i<k-1;i++)
            mx+=v[i];
        
        
        return mx-mn;
    }
};