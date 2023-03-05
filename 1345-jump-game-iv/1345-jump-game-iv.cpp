class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,queue<int>> m;
        int n=arr.size();
        for(int i=0;i<n;i++)
            m[arr[i]].push(i);
        vector<int> dis(n,-1);
        queue<int> q;
        q.push(0);
        dis[0]=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i-1>=0 && dis[i-1]==-1){
                dis[i-1]=dis[i]+1;
                q.push(i-1);
            }
            if(i+1<n && dis[i+1]==-1)
            {
                dis[i+1]=dis[i]+1;
                q.push(i+1);
            }
            while(!m[arr[i]].empty()){
                int j=m[arr[i]].front();
                m[arr[i]].pop();
                if(dis[j]==-1)
                {
                    dis[j]=dis[i]+1;
                    q.push(j);
                }
            }
        }
        return dis[n-1];
    }
};