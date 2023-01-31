class Solution {
public:
    int calculate(string s) {
        int sign=1;
        int n=s.length();
        int i=0;
        int res=0;
        stack<int> st;
        while(i<n){
            if(s[i]=='+'){
                sign=1;
            }
            
           else if(s[i]=='-'){
                sign=-1;
           }
            
           else if(isdigit(s[i])){
                int num=s[i]-'0';
                while(i+1<n && isdigit(s[i+1])){
                    num=num*10+(s[i+1]-'0');
                    i++;
                }
                res+=num*sign;
              
            }
            
            
           else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            
            
          else if(s[i]==')'){
                int preSign=st.top();
                st.pop();
                int preRes=st.top();
                st.pop();
                res=res*preSign+preRes;
             
            }
            
            
            i++;
        }
        return res;
    }
};