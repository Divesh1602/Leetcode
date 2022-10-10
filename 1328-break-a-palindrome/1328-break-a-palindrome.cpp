class Solution {
public:
    bool ispalindrome(string p){
        string s=p;
        reverse(s.begin(),s.end());
        return (s==p);
    }
    string breakPalindrome(string p) {
        set<string> s;
      for(int i=0;i<p.length();i++){
          int x=p[i];
          for(char y='a';y<='z';y++){
              p[i]=y;
          if(ispalindrome(p))
              p[i]=x;
          else
          {
              s.insert(p);
              p[i]=x;
          }
          }
      }
        
       for(auto x:s)
           return x;
        p="";
        return p;
    }
};