class Solution {
    class DisjointSet{
        public:
        vector<int>parent,rank;
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUp(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUp(parent[node]);
        }
        void unionByRank(int u,int v){
            int up_u=findUp(u);
            int up_v=findUp(v);
            if(up_u==up_v) return;
            else if(rank[up_u]<rank[up_v]){
                parent[up_u]=up_v;
            }
            else if(rank[up_u]>rank[up_v]){
                parent[up_v]=up_u;
            }
            else{
                parent[up_v]=up_u;
                rank[up_u]++;
            }
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        DisjointSet alice(n+1);
        DisjointSet bob(n+1);
        int ans1=0,ans2=0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                bool flag=false;
                if(alice.findUp(edges[i][1])!=alice.findUp(edges[i][2])){
                    alice.unionByRank(edges[i][1],edges[i][2]);
                    flag=true;
                }
                if(bob.findUp(edges[i][1])!=bob.findUp(edges[i][2])){
                    bob.unionByRank(edges[i][1],edges[i][2]);
                    flag=true;
                }
                if(flag)
                ans1++;

            }
            else if(edges[i][0]==1){
                if(alice.findUp(edges[i][1])!=alice.findUp(edges[i][2])){
                    alice.unionByRank(edges[i][1],edges[i][2]);
                    ans1++;
                }
            }
            else{
                if(bob.findUp(edges[i][1])!=bob.findUp(edges[i][2])){
                    bob.unionByRank(edges[i][1],edges[i][2]);
                    ans2++;
                }
            }
        }
        
        int cnt=0;
        int cnt2=0;
        for(int i=1;i<=n;i++){
            if(alice.findUp(i)==i) cnt++;
        }
        for(int i=1;i<=n;i++){
            if(bob.findUp(i)==i) cnt2++;
        }
        if(cnt>1||cnt2>1) return -1;


        return edges.size()-ans1-ans2;
    }
};