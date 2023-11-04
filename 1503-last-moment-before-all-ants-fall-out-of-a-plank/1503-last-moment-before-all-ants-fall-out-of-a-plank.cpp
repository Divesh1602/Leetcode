class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
         if(left.empty())
            return n - *min_element(right.begin(), right.end()); 
            
        if(right.empty())
            return *max_element(left.begin(), left.end());
        
        int a = *max_element(left.begin(), left.end());
        int b = *min_element(right.begin(), right.end());

        return max(n-b, a);
    }
};