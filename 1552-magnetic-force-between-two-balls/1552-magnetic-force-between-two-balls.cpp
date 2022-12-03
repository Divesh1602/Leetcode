class Solution {
public:
    bool isvalid(int n,int m,vector<int>& position,int mid){
    int ct=1;
    int balls=position[0];
    for(int i=1;i<n;i++){
        if(position[i]-balls>=mid){
            ct++;
            balls=position[i];
        }
    }
    return(ct>=m);
}
    int maxDistance(vector<int>& position, int m) {
         int ans=0;
        int n=position.size();
        int i=1,j=0;
        sort(position.begin(),position.end());
        j=position[n-1];
        while(i<=j){
            int mid=(i+j)/2;
            if(isvalid(n,m,position,mid)){
                ans=mid;
                i=mid+1;
            }
            else
            j=mid-1;
        }
        return ans;
    }
};