class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word="";
        stringstream str(s);
        while(str>>word)
            v.push_back(word);
        for(int i=0;i<v.size();i++){
            reverse(v[i].begin(),v[i].end());
        }
        string ans="";
        for(auto a:v){
            ans+=a+" ";
        }
            int n=ans.length()-1;
        ans.erase(n,n);
        return ans;
    }
};