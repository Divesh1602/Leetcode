//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int n) {
        // code here
        if(n==0)
        return 0;
        
        int a[n+1];
        a[0]=0;
        a[1]=1;
        a[2]=2;
        for(int i=3;i<=n;i++){
            a[i]=(a[i-1]+a[i-2])%100000000;
        }
        return a[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends