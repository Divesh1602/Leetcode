class Solution {
public:
    int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
    int alternateDigitSum(int n) {
        int x=reverseDigits(n);
        bool flag=true;
        int ans=0;
        while(x!=0){
            int md=x%10;
            if(flag){
                ans+=md;
                flag=false;
            }
            else
            {
                ans-=md;
                flag=true;
            }
            x=x/10;
        }
        return ans;
    }
};