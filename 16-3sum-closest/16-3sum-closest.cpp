class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
     int diff,diff1=INT_MAX,res=INT_MAX;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=a[i]+a[j]+a[k];
                if(sum==t)
                    return sum;
                diff=abs(t-sum);
                if(diff<diff1){
                    res=sum;
                    diff1=diff;
                }
                if(sum<t)
                    j++;
                else if(sum>t)
                    k--;
            }
        }
        return res;
    }
};