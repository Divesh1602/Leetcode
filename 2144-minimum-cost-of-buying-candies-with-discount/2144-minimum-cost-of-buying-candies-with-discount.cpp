class Solution {
public:
    int minimumCost(vector<int>& a) {
        int res=0;
        sort(a.begin(),a.end());
       for(int i=a.size()-1;i>=0;i=i-3){
           if(i>0)
               res+=a[i]+a[i-1];
           else if(i==0)
               res+=a[i];
       }
        return res;
    }
};