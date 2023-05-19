class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // bool stat=false;
        int n=graph.size();
        vector<bool> visit(n, false);
        set<int> a,b;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            if(!visit[i]){
                q.push({i,0});
        while(!q.empty()){
            int cur=q.front().first;
            int stat=q.front().second;
            q.pop();
            visit[cur]=true;
            for(int node:graph[cur]){
                if(stat && !visit[node]){
                    b.insert(node);
                    q.push({node, 0});
                    visit[node]=true;
                }
                if(!stat && !visit[node]){
                    a.insert(node);
                    q.push({node, 1});
                    visit[node]=true;
                }
            }
        }
            }
        }
        for(int x:a){
            for(int v:graph[x]){
                if(a.find(v) != a.end()){
                    return false;
                }
            }
        }
        for(int x:b){
            for(int v:graph[x]){
                if(b.find(v) != b.end()){
                    return false;
                }
            }
        }
        return true;
    }
};