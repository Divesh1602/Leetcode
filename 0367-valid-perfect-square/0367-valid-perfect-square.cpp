class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i=0;i*i<=num;i++)
            if((long long)(i*i)==num)
                return true;
        return false;
    }
};