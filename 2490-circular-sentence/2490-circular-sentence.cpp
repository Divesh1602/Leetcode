class Solution {
public:
    bool isCircularSentence(string sentence) {
       stringstream s(sentence);
        string word;
        vector<string> words;
        while(s>>word)
            words.push_back(word);
        int n=words.size();
        for(int i=0;i<n;i++){
            if(words[i][words[i].size()-1]!=words[(i+1)%n][0])
                return false;
        }
        return true;
    }
};