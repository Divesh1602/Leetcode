class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
  
        stringstream s(s1);
        string word;
        unordered_map<string,int> res;
        while(s >> word)
            res[word]++;
        stringstream str(s2);
       
        while(str >> word)
            res[word]++;
        vector<string> ans;
       for(auto a:res)
           if(a.second==1)
               ans.push_back(a.first);
        
        return ans;
    }
};