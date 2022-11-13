class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            string res="";
            while(s[i]!=' '){
                res+=s[i];
                i--;
                if(i<0)
                    break;
            }
            reverse(res.begin(),res.end());
            
            if(res.length()>0){
            ans+=res;
            ans+=" ";
            }
        }
        string ans1="";
        for(int i=0;i<ans.length()-1;i++){
            ans1+=ans[i];
        }
        return ans1;
    }
};