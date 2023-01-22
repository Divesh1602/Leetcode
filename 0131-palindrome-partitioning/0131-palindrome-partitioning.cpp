class Solution {
public:
    void helper(string s, int start, vector<string>& temp, vector<vector<string>>& res)
    {
        if(start==s.length())
        {
            res.push_back(temp);
            return;
        }
        string str="";
        for(int i=start; i<s.length(); i++)
        {
            str=s.substr(start, i-start+1);
            string str1=str;
            reverse(str.begin(), str.end());
            if(str1==str)
            {
                temp.push_back(str);
                helper(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> temp;
        helper(s, 0, temp, res);
        return res;
    }
};