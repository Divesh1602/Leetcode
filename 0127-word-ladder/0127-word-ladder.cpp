class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({startWord,1});
        int ans=0;
        set<string> s;
        for(auto a:wordList)
        s.insert(a);
        if(s.find(startWord)!=s.end())
        s.erase(startWord);
        while(!q.empty()){
            string s1=q.front().first;
            int lev=q.front().second;
            q.pop();
            if(s1==targetWord){
                ans=lev;
                return ans;
            }
            string s2=s1;
            for(int i=0;i<s1.length();i++){
            
                for(char c='a';c<='z';c++){
                    s2[i]=c;
                    if(s.find(s2)!=s.end()){
                        q.push({s2,lev+1});
                        s.erase(s2);
                    }
                    s2=s1;
                }
            }
        }
        return ans;
    }
};