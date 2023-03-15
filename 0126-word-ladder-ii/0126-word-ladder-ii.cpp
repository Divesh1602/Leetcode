class Solution {
    unordered_map<string,int> m;
    vector<vector<string>> ans;
    string b;
    private:
    void dfs(string s1,vector<string>& seq){
        if(b==s1){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=m[s1];
        int sz=s1.length();
        for(int i=0;i<sz;i++){
            char org=s1[i];
                for(char c='a';c<='z';c++){
                    s1[i]=c;
                    if(m.find(s1)!=m.end() && steps==m[s1]+1){
                        seq.push_back(s1);
                        dfs(s1,seq);
                        seq.pop_back();
                    }
                    s1[i]=org;
                }
            }
        
        
        
    }
public:
    vector<vector<string>> findLadders(string startWord, string targetWord, vector<string>& wordList) {
        queue<string> q;
        q.push({startWord});
        m[startWord]=1;
        b=startWord;
        unordered_set<string> s;
        int sz=startWord.length();
        for(auto a:wordList)
        s.insert(a);
       
        s.erase(startWord);
        while(!q.empty()){
            string s1=q.front();
          
            q.pop();
            int steps=m[s1];
            if(s1==targetWord)
                break;
            
            for(int i=0;i<sz;i++){
            char org=s1[i];
                for(char c='a';c<='z';c++){
                    s1[i]=c;
                    if(s.find(s1)!=s.end()){
                        q.push({s1});
                        m[s1]=steps+1;
                        s.erase(s1);
                    }
                    s1[i]=org;
                }
            }
        }
        if(m.find(targetWord)!=m.end()){
            vector<string> seq;
            seq.push_back(targetWord);
            dfs(targetWord,seq);
    }
        return ans;
        
    }
};