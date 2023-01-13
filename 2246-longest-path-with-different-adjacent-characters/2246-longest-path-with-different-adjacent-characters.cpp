class Solution {
public:


int ANS = 0;
int fun(vector<int> adj[] , string &s , int root,vector<int> & vis){
vis[root]=1;
int left = 0;
int MAX_ANS = 0;
int ans2=0;
int ans1=0;
for(auto it :adj[root]){
if(vis[it]==0){
int temp =0;
temp=fun(adj,s,it,vis);
if(s[it]==s[root]){

}else{
if(temp>ans1){
    ans2=max(ans1,ans2);
    ans1=temp;
}else if(temp>ans2){
    ans2=temp;
}
}
}
}
ANS = max(ANS,ans1+ans2+1);
return ans1+1;



}




    int longestPath(vector<int>& parent, string s) {

int n = s.size();
vector<int> adj[n];
for(int i=1; i<parent.size(); i++){
    adj[parent[i]].push_back(i);
    adj[i].push_back(parent[i]);
}
vector<int> vis(n,0);

 fun(adj,s,0,vis);

        return ANS;
    }
};