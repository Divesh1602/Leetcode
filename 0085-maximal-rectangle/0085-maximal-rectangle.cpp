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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        vector<vector<int>> v(r,vector<int>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                v[i][j]=matrix[i][j]-'0';
                
            }
        }
        
        
        int res=largestRectangleArea(v[0]);
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(v[i][j]==1)
                    v[i][j]+=v[i-1][j];
            }
            res=max(res,largestRectangleArea(v[i]));
        }
        return res;
    }
};