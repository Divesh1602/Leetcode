//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& a, int n) {
        set<int> s;
        s.insert(a[n-1]);
        vector<int> ans;
        ans.push_back(-1);
        int mx=a[n-1];
        for(int i=n-2;i>=0;i--){
             s.insert(a[i]);
            if(a[i]<mx){
                auto pos=s.find(a[i]);
                pos++;
                ans.push_back(*pos);
            }
            else{
                mx=a[i];
                ans.push_back(-1);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends