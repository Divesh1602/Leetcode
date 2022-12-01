class Solution {
public:
    bool halvesAreAlike(string s) {
        int mid=s.length()/2;
        int ct1=0,ct2=0;
        for(int i=0;i<mid;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                ct1++;
        }
           for(int i=mid;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                ct2++;
        }
        return (ct1==ct2);
    }
};