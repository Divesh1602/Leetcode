class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int sum=0;
        for(int i=0;i<n-2;i++){
            if(a[i]+a[i+1]>a[i+2]){
                sum=a[i]+a[i+1]+a[i+2];
            }
        }
        return sum;
    }
};