//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
     
        vector<int> ans;
        	int t=0,l=0,r=C-1,b=R-1;
	while(t<=b && l<=r){
		for(int i=l;i<=r;i++)
		ans.push_back(a[t][i]);
		t++;
		for(int i=t;i<=b;i++)
		ans.push_back(a[i][r]);
		r--;
		if(t<=b){
			for(int i=r;i>=l;i--)
			ans.push_back(a[b][i]);
			b--;
		}
		if(l<=r){
			for(int i=b;i>=t;i--)
			ans.push_back(a[i][l]);
			l++;
		}
	}
	reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends