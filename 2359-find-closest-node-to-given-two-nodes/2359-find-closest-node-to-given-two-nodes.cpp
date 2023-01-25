class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int n1, int n2) {
        int n=edges.size();
        vector<pair<int,int>>st(n,{-1,-1});
        int i=0;
        while(n1!=-1 && st[n1].first==-1){
            st[n1].first=i;
            i++;
            n1=edges[n1];
        }
        i=0;
        while(n2!=-1 && st[n2].second==-1){
            st[n2].second=i;
            i++;
            n2=edges[n2];
        }
        int mini=INT_MAX,node;
        for(int i=0;i<n;i++){
            if(st[i].first!=-1 && st[i].second!=-1){
                
                if(max(st[i].first,st[i].second)<mini)
                {
                    mini=max(st[i].first,st[i].second);
                    node=i;
                }
            }
        }
        if(mini==INT_MAX)return -1;
        return node;

    }
};