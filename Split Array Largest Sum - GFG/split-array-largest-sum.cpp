//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(int arr[],int n,int k,int mid){
      int sum=0;
      int ct=1;
     for(int i=0;i<n;i++){
       if(sum+arr[i]>mid){
          ct++;
           sum=arr[i];
       }
       else
       sum+=arr[i];
     
     }
      return (ct<=k);
  }
    int splitArray(int arr[] ,int n, int k) {
        // code here
        int ans=0;
       
        int i=INT_MIN;
        int j=0;
        
        for(int x=0;x<n;x++){
        j+=arr[x];
        i=max(i,arr[x]);
        }        
        while(i<=j){
            int mid=(i+j)/2;
            if(check(arr,n,k,mid)){
                ans=mid;
                j=mid-1;
            }
            else
            i=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends