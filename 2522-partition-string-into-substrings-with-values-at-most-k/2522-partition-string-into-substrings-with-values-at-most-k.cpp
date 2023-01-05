class Solution {
public:
    int minimumPartition(string s, int k) {
        int ct=1;
        string ans="";
        for(int i=0;i<s.length();i++){
            char str=s[i];
            long long ch=int(str-'0');
            if(ch>k)
                return -1;
            ans+=s[i];
            stringstream ss;
            ss<<ans;
            long long chk;
            ss>>chk;
            if(chk>k){
                ct++;
                ans=s[i];
            }
        }
        return ct;
    }
};