class Solution {
public:
    int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
    
    long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(auto a: nums){
            int n=a;
            while(!st.empty() && gcd(st.top(),n)>1){
                int element=st.top();
                st.pop();
                n=lcm(element,n);
            }
            
                st.push(n);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
        st.pop();
    }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};