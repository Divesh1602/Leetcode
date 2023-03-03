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
    int strStr(string haystack, string needle) {
        int m=needle.length();
        int n=haystack.length();
    vector<int> ans=prefix(needle,m);
        int i=0,j=0;
        
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m)
                return i-j;
            else if(i<n && haystack[i]!=needle[j]){
                if(j==0)
                    i++;
                else
                    j=ans[j-1];
            }
            
        }
        return -1;
    }
};