class Solution {
public:
    int countDigits(int num) {
        int x=num;
        int ans=0;
        while(num>0){
            int n=num%10;
            if(x%n==0)
                ans++;
            num=num/10;
        }
        return ans;
        
    }
};