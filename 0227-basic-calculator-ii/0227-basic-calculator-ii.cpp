class Solution {
public:
    int calculate(string s) {
        s+='+';
        
        stack<int> st;
        char sign='+';
        
        int curr=0,res=0;
        
        
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i]))
                curr=curr*10 + (s[i]-'0');
            
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
               
                if(sign=='+')
                    st.push(curr);
                
                else if(sign=='-')
                    st.push(curr*(-1));
                
                else if(sign=='*'){
                    int num=st.top();
                    st.pop();
                    st.push(num*curr);
                }
                
                else if(sign=='/'){
                    int num=st.top();
                    st.pop();
                    st.push(num/curr);
                }
                
                curr=0;
                sign=s[i];
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};