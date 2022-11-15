class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream str(s);
        string word;
        int res;
        while(str >> word){
            res=word.length();
        }
        return res;
    }
};