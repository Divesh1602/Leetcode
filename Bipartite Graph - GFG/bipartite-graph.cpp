//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

bool chk(int start,vector<int>adj[],vector<int>& color){
     queue<int> q;
	    q.push(start);
	   
	    color[start]=0;
	    while(!q.empty()){
	        int curr=q.front();
	        q.pop();
	        
	        for(auto a:adj[curr]){
	            if(color[a]==-1){
	            color[a]=!color[curr];
	            q.push(a);
	            }
	            else if(color[a]==color[curr])
	            return false;
	        }
	    }
	    return true;
}
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	     vector<int> color(v,-1);
	   for(int i=0;i<v;i++){
	       if(color[i]==-1){
	           if(chk(i,adj,color)==false)
	           return false;
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends