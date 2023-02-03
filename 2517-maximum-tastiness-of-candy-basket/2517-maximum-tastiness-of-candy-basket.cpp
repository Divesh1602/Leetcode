class Solution {
public:
    bool isChk(int mid,vector<int>& price,int k){
        int n=price.size();
        int x=price[0];
        int ct=1;
        for(int i=1;i<n && ct<k;i++){
            if(price[i]-x>=mid)
                x=price[i],ct++;
        }
        return (ct==k);
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int i=1,j=1e9;
        int ans=0;
        while(i<j){
            int mid=i+(j-i)/2;
            if(isChk(mid,price,k)){
                i=mid+1;
                ans=mid;
            }
            else 
                j=mid;
        }
        return ans;
    }
};