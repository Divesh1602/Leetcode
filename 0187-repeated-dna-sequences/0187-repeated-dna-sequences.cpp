class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int j=0;
        int n=s.length();
        string t="";
        while(j<n){
            
            t+=s[j];
            if(t.length()==10){
                m[t]++;
                t.erase(t.begin());
               
            }
            j++;
        }
        vector<string> ans;
        for(auto a:m){
            if(a.second>1)
                ans.push_back(a.first);
           
        }
        return ans;
    }
};