class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int n=pushed.size();
        stack<int> st;
       for(int j=0;j<n;j++){
           if(!st.empty() && st.top()==popped[j]){
               st.pop();
               continue;
           }
           if(i<n && pushed[i]!=popped[j]){
               while(pushed[i]!=popped[j] && i<n){
                   st.push(pushed[i]);
                   i++;
               }
              i++;
           }
           else if(i<n && pushed[i]==popped[j])
               i++;
           
       }
        return (st.empty());
    }
};