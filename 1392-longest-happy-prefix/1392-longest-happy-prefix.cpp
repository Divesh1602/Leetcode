class Solution {
public:
    vector<int> prefix(string s,int n){
        vector<int> lps(n);
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                 i++;
                
            }
            else{
                if(len==0){
                    lps[i]=0;
                        i++;
                    }
                else{
                    len=lps[len-1];
                }
                
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        int n=s.length();
    vector<int> ans=prefix(s,s.length());
        return s.substr(0,ans[n-1]);
    }
};