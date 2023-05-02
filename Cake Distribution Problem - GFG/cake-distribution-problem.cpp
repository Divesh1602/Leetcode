//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool isValid(int mid,vector<int>& nums,int k){
        int sum=0;
        int ct=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=mid){
                ct++;
                sum=0;
            }
            
            
        }
        return (ct>=k);
    }
    int maxSweetness(vector<int>& sweetness, int n, int k) {
    // Write your code here.
    int i=0,j=INT_MAX;
    int ans=0;
    while(i<=j){
        int mid=(i+j)/2;
                    
        if(isValid(mid,sweetness,k+1)){
            ans=mid;
            i=mid+1;
        }
        else
        j=mid-1;
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends