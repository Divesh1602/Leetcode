class Solution {
public:
    vector<int> kmp(string s,int n){
        vector<int> lps(n);
        lps[0]=0;
        int i=1;
        int len=0;
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
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        string ans=s+s;
        vector<int> v=kmp(ans,ans.length());
        int n=ans.length();
        int m=goal.length();
        int i=0,j=0;
        while(i<n){
            if(ans[i]==goal[j]){
                i++;
                j++;
            }
            if(j==m)
                return true;
            else if(i<n && ans[i]!=goal[j]){
                if(j==0)
                    i++;
                else{
                    j=v[j-1];
                }
            }
        }
        return false;
    }
};