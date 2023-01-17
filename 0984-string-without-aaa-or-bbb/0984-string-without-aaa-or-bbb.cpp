class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a && b){
            if(b>a){
                ans+="bba";
                b-=2;
                a--;
            }
            else if(a>b){
                ans+="aab";
                a-=2;
                b--;
            }
            else{
                ans+="ba";
                a--;
                b--;
            }
        }
        while(b){
            ans+="b";
            b--;
        }
        while(a){
            ans+="a";
            a--;
        }
        return ans;
    }
};