//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution

{

 public:
  long long helper(int x,vector<int>& nums){
	long long sum=x;
	int i=x;
	x=nums[x];
	while(x!=i){
    sum+=x;
	x=nums[x];
	}
	return sum;
}
  long long largestSumCycle(int n, vector<int> nums)

  {

  long long ans=0;
		vector<bool> visited(n,false);

		for(int i=0;i<nums.size();i++){
			if(!visited[i]){
				unordered_set<int> s;
				s.insert(i);
				bool flag=true;
				int x=nums[i];
				visited[i]=true;
				while(s.find(x)==s.end()){
                    if(x==-1 || visited[x]){
						flag=false;
						break;
					}
					visited[x]=true;
					s.insert(x);
                    x=nums[x];

				}

				if(flag){
					ans=max(ans,helper(x,nums));
				}
			}
		}
           
		  if(ans==0)
		  return -1;
		  else
		   return ans;

    

    

    

  }

};


//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends