class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int sum=0;
        for(int i=n-1;i>1;i--){
            if(a[i-2]+a[i-1]>a[i]){
                sum=a[i]+a[i-1]+a[i-2];
                return sum;
            }
        }
        return sum;
    }
};