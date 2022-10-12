class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
       int n=a.size();
        int mx=INT_MAX;
        int mx1=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]<mx)
                mx=a[i];
            else if(a[i]>mx && a[i]<mx1)
                mx1=a[i];
            else if(a[i]>mx1)
                return true;
        }
        return false;
    }
};