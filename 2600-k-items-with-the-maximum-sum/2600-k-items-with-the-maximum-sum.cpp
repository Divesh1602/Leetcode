class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeroes, int numNegOnes, int k) {
     if(numOnes>=k)
         return k;
    if(numOnes+numZeroes>=k)
        return numOnes;
        
        k-=numOnes+numZeroes;
        return numOnes-k;
        
    }
};