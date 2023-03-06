//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
   int noConseBits(int n) {
        int i=31;
        int c = 0;
        while(i >= 0){
            if(n&(1<<i))
                c++; //set bit found
            else
                c = 0; //unset bit found
            if(c == 3){
                n = (n&(~(1<<i))); // clearing the current bit
                c = 0;
            }
            i--;
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends