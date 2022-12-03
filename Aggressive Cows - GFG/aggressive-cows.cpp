//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
bool isvalid(int n,int k,vector<int>& stalls,int mid){
    int ct=1;
    int cow=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-cow>=mid){
            ct++;
            cow=stalls[i];
        }
    }
    return(ct>=k);
}
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int ans=0;
        int i=1,j=0;
        sort(stalls.begin(),stalls.end());
        j=stalls[n-1];
        while(i<=j){
            int mid=(i+j)/2;
            if(isvalid(n,k,stalls,mid)){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends