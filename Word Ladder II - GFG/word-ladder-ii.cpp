//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        set<string> s;
        for(auto a:wordList)
        s.insert(a);
        int lev=0;
        vector<string> usedOn;
        usedOn.push_back(beginWord);
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            if(vec.size()>lev){
                lev++;
                for(auto a:usedOn)
                s.erase(a);
            }
           
           string s1=vec.back();
           if(s1==endWord){
               if(ans.size()==0){
                   ans.push_back(vec);
               }
               else if(ans[0].size()==vec.size())
               ans.push_back(vec);
           }
            for(int i=0;i<s1.length();i++){
                char org=s1[i];
                for(char c='a';c<='z';c++){
                    s1[i]=c;
                    if(s.find(s1)!=s.end()){
                       vec.push_back(s1);
                       q.push(vec);
                       vec.pop_back();
                       usedOn.push_back(s1);
                    }
                    s1[i]=org;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends