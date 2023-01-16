class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int i=0,j=0;
        int n=s.length();
        string t="";
        while(j<n){
            
            t+=s[j];
            if(j-i+1==10){
                m[t]++;
                t.erase(t.begin());
                i++;
                
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