class disjointset{
    vector<int> parent;
    vector<int> rank;
    public:
    disjointset(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i] = i;
        rank.resize(n+1);
        for(int i=0;i<=n;i++)rank[i] = 0;
    }
    int findUpar(int node){
        if(parent[node] == node)return node;
        return parent[node] = findUpar(parent[node]);
    }
    void make_union(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;//connect smaller to larger 
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    bool connected(int i,int j){return findUpar(i) == findUpar(j);}
};
class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2] < b[2];
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
    
        disjointset ds(n+1);
        for(int i=0;i<q.size();i++)q[i].push_back(i);
        sort(edges.begin(),edges.end(),cmp);
        sort(q.begin(),q.end(),cmp);
        int j = 0;
        vector<bool> ans(q.size(),false);
        for(int i=0;i<q.size();i++){
            int u = q[i][0];
            int v = q[i][1];
            int limit = q[i][2];
            int ind = q[i][3];
            for(;j<edges.size() && edges[j][2]<limit;j++){
                ds.make_union(edges[j][0],edges[j][1]);
            }
            ans[ind] = ds.connected(u,v);
        }
        return ans;
        
    }
};