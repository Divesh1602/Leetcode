class Solution {
public:
    int numDifferentIntegers(string word) {
       vector<string> s;
        for(int i=0;i<word.length();i++){
            if(isdigit(word[i])==true){
                while(word[i]=='0')
                    i++;
                string ans="";
                while(isdigit(word[i])==true){
                    ans+=word[i];
                    i++;
                }
                cout<<ans<<endl;
                s.push_back(ans);
            }
        }
        unordered_set<string> res;
        for(auto a:s)
            res.insert(a);
        return res.size();
    }
};