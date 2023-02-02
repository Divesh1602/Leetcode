class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ct=0;
        int n=s.length();
        int ans=0;
        while(j<n){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
                ct++;
            if(j-i+1<k)
                j++;
            else{
                ans=max(ans,ct);
                 if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                     ct--;
                i++;
                j++;
            }
        }
        return ans;
    }
};