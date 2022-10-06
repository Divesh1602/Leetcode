class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        int res=0;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i=i+2){
            res+=a[i];
        }
        return res;
    }
};