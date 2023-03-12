class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            char c=words[i][0];
            char c1=words[i][words[i].length()-1];
            if((c=='a' || c=='e' || c=='i' || c=='o' || c=='u') && (c1=='a' || c1=='e' || c1=='i' || c1=='o' || c1=='u'))
                ans++;
        }
        return ans;
    }
};