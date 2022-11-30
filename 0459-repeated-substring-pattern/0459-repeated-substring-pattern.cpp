class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string x="",y;
        for(int i=0;i<s.length()/2;i++){
            x+=s[i];
            y=x;
            if(s.length()%y.length()==0){
                int n=s.length()/x.length();
                while(n>1){
                    y+=x;
                    n--;
                }
                if(y==s)
                    return true;
            }
        }
        return false;
    }
};