//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> nums(n);
        nums=arr;
        sort(nums.begin(),nums.end());
       unordered_map<long long,long long> m;
        long long sum=0;
        m[nums[0]]=0;
        long long ct=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                ct++;
            }
            else{
                
                sum+=nums[i-1]*ct;
                ct=1;
            }
            m[nums[i]]=sum;
            
            
        }
      
        vector<long long> ans;
        for(int i=0;i<n;i++){
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends