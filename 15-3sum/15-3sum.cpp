class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
       vector<vector<int>> res;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;){
            int j=i+1,k=n-1;
            
            while(j<k){ 
                int sum=a[i]+a[j]+a[k];
                if(sum==0){
                    res.push_back({a[i],a[j],a[k]});
                    j++;
                    k--;
                    while(a[j]==a[j-1])
                        {
                        j++;
                        if(j>=k)
                         break;
                        
                        }
                }
                else if(sum>0)
                    k--;
                else{
                    j++;
                    while(a[j]==a[j-1])
                        {
                        j++;
                        if(j>=k)
                         break;
                        
                        }
                }
              
            }
            i++;
           while(a[i]==a[i-1]){
              i++;
               if(i>=n-2)
                  break;
            
           }
        }
       
       
        return res;
    }
};