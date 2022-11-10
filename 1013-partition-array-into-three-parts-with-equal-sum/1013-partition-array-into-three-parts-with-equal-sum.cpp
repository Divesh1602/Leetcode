class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int sum=0,sum1=0;
        for(int k=0;k<arr.size();k++){
            sum+=arr[k];
        }
        int ct=3;
        if(sum%3!=0)
        return false;
        sum=sum/3;
        for(auto i:arr){
            sum1+=i;
            if(sum1==sum){
                ct--;
                sum1=0;
            }
        }
        return (ct<=0);
    }
};