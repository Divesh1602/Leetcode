class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int n=heights.size();
       
       
        stack<int> st;
        int curr=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                int t= st.top();
                st.pop();
                curr=heights[t]*((st.empty())? i:(i-st.top()-1));
                res=max(res,curr);
              
            }
               
            
            st.push(i);
        }
        
       
        
       while(!st.empty())
       {
           int tp= st.top();
           st.pop();
                curr=heights[tp]*((st.empty())? n:(n-st.top()-1));
                res=max(res,curr);
       }
        return res;
    }
};