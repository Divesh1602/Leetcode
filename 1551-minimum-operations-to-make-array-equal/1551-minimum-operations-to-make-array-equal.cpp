class Solution {
public:
    int minOperations(int n) {
        int ans=0;
       if(n%2==0){
           int i=n/2;
           int mid=((2*i)+1+(2*(i-1))+1)/2;
            for(int j=0;j<i;j++){
                int element=(2*j)+1;
                ans+=mid-element;
            }
       }
        else{
            int i=n/2;
            int mid=(2*i)+1;
            for(int j=0;j<i;j++){
                int element=(2*j)+1;
                ans+=mid-element;
            }
        }
        return ans;
    }
};