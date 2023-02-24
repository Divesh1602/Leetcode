class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(auto a:nums){
            if(a%2!=0)
                s.insert(a*2);
            else
                s.insert(a);
        }
        
        int ans=*s.rbegin()-*s.begin();
        
        while(*s.rbegin()%2==0){
            int x=*s.rbegin();
            s.erase(x);
            x=x/2;
            s.insert(x);
            ans=min(ans,*s.rbegin()-*s.begin());
        }
        return ans;
    }
};