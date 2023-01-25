class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; 
        
        for( int i =0 ; i < s.size();i++)
        {
          char ch = s[i]; 
          if(ch =='('|| ch =='{'|| ch =='[')
          {
              stk.push(ch); 
          }
          else {
              if(stk.empty())
              {
                  return 0 ; 
              }
              if((ch==')' && stk.top()=='(') || (ch=='}' && stk.top()=='{')|| (ch==']' && stk.top()=='['))
              {
                  stk.pop(); 
              }
              else{
                     return false ; 
          }
          }
        }
        return stk.empty();
         
    }
};