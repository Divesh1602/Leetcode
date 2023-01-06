class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(char c: t)
            m[c]++;
        int i=0;
        int ct=m.size();
        string anstr="";
        int ans=INT_MAX;
       int start=0;
        for(int j=0;j<s.length();j++){
            
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    ct--;
                    if(ct==0){
                        while(ct==0){
                            if(ans>j-i+1){
                                ans=j-i+1;
                               start=i;
                            }
                            if(m.find(s[i])!=m.end()){
                                m[s[i]]++;
                               if(m[s[i]]>0)
                                   ct++;
                            }
                            i++;
                        }
                    }
                }
            }
            
        }
        if(ans==INT_MAX)
            return "";
        return s.substr(start,ans);
    }
};