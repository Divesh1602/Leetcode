class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int n=heights.size();
        vector<int> ps;
        vector<int> ns;
        ps.push_back(-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>= heights[i])
                st.pop();
            ps.push_back((st.empty())? -1:st.top());
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        ns.push_back(n);
        st.push(n-1);
        
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>= heights[i])
                st.pop();
            ns.push_back((st.empty())? n:st.top());
            st.push(i);
        }
        reverse(ns.begin(),ns.end());
        int curr=0;
        for(int i=0;i<n;i++){
            curr=heights[i];
            curr+=(i-ps[i]-1)*heights[i];
            curr+=(ns[i]-i-1)*heights[i];
            res=max(res,curr);
        }
        return res;
    }
};