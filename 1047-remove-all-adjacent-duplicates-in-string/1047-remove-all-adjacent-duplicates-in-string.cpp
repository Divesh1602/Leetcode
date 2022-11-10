class Solution {
public:
    string removeDuplicates(string s) {
        int i=1;
        for(int j=1;j<s.length();j++){
            if(i>0 && s[i-1]==s[j])
            i--;
            else{
                s[i]=s[j];
                i++;
            }
        }
        return s.substr(0,i);
    }
};