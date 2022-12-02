class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=k || n<=2*k){
            vector<int> res(n,-1);
            return res;
        }
        cout<<n;
       long long sum=0;
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(-1);
        int num=2*k+1;
        int j=0;
        for(j=0;j<num;j++)
            sum+=nums[j];
       
        ans.push_back(sum/num);
        int i=0;
        int x=k+1;
        while(x<n-k){
            sum-=nums[i];
            sum+=nums[j];
            i++;
            j++;
            
             int avg=sum/num;
            ans.push_back(avg);
            x++;
            
        }
        for(int a=n-k;a<n;a++)
            ans.push_back(-1);
        return ans;
    }
};