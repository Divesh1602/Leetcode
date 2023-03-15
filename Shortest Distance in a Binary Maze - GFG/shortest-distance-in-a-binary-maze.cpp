//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> des) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        
        dis[src.first][src.second]=0;
        priority_queue<pair<int ,pair<int,int>>,vector<pair<int ,pair<int,int>>>,greater<pair<int ,pair<int,int>>>> pq;
        
        pq.push({0,{src.first,src.second}});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    if(d+1<dis[nrow][ncol]){
                        dis[nrow][ncol]=d+1;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        
        return (dis[des.first][des.second]==INT_MAX)?-1:dis[des.first][des.second];
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends