class Solution {
public:
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
    bool isReachable(int targetX, int targetY) {
        while(targetX%2==0)
            targetX/=2;
        while(targetY%2==0)
            targetY/=2;
        return gcd(targetX,targetY)==1;
    }
};