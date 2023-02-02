class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>> st;
        if(s.length()<k)
            return s;
        for(int i=0;i<s.length();i++){
            if(st.empty() || st.top().first!=s[i])
                st.push({s[i],1});
            else{
                auto itr=st.top();
                st.pop();
                st.push({s[i],itr.second+1});
            }
            
            if(st.top().second==k)
                st.pop();
        }
        string ans="";
        
        while(!st.empty()){
            auto itr=st.top();
            while(itr.second--)
                ans+=itr.first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};