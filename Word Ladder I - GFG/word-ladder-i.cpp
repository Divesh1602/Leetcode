//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends