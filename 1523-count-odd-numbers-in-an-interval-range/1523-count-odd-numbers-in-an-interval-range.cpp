class Solution {
public:
    int countOdds(int low, int high) {
        int n=(high-low);
        if(n%2==0)
            n=n/2;
        
        else{
            if(low%2!=0)
                n=n/2+1;
            else
                n=n/2;
        }
        if(high%2!=0)
            n++;
        return n;
    }
};