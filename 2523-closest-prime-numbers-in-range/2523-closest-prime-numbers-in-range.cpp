class Solution {
public:
    bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for(int i=left;i<=right;i++){
            if(isPrime(i))
                prime.push_back(i);
        }
        
        int mn=INT_MAX;
        vector<int> ans{-1,-1};
        for(int i=1;i<prime.size();i++){
            int cl=prime[i]-prime[i-1];
            if(cl<mn){
                ans[0]=prime[i-1];
                ans[1]=prime[i];
                mn=cl;
            }
        }
        return ans;
    }
};