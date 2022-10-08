class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
       vector<vector<int>> res;
        set<vector<int>> s;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=a[i]+a[j]+a[k];
                if(sum==0){
                    s.insert({a[i],a[j],a[k]});
                    j++;
                    k--;
                }
                else if(sum>0)
                    k--;
                else
                    j++;
            }
        }
        for(auto x:s)
            res.push_back(x);
       
        return res;
    }
};