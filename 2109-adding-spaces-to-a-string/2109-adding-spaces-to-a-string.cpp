class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0,j=0;
        string ans="";
        while(i<s.length()){
            if(j<spaces.size() && i==spaces[j]){
                ans+=" ";
                j++;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};