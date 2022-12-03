class Solution {
public:
    bool isvalid(int n,int k,vector<int>& stalls,int mid){
    int ct=1;
    int cow=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-cow>=mid){
            ct++;
            cow=stalls[i];
        }
    }
    return(ct>=k);
}
    int maxDistance(vector<int>& stalls, int k) {
         int ans=0;
        int n=stalls.size();
        int i=1,j=0;
        sort(stalls.begin(),stalls.end());
        j=stalls[n-1];
        while(i<=j){
            int mid=(i+j)/2;
            if(isvalid(n,k,stalls,mid)){
                ans=mid;
                i=mid+1;
            }
            else
            j=mid-1;
        }
        return ans;
    }
};