class Solution {
public:
    int minimumPartition(string s, int k) {
        int ct=1;
        long long num=0;
        for(int i=0;i<s.length();i++){
        num=num*10+s[i]-'0';
            if(num>k)
            {
                ct++;
                num=s[i]-'0';
            }
            if(num>k)
                return -1;
        }
        return ct;
    }
};