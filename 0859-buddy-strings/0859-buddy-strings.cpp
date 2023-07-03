class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return 0;
        if(s==goal){
            unordered_map<char,int> m;
            for(auto a:s)
                m[a]++;
            for(auto a:m)
                if(a.second>1)
                    return true;
            return false;
        }
        unordered_map<char, int> a, b;
        for(auto i : s) a[i]++;
        for(auto i : goal) b[i]++;

        int count = 0; 
        for(int i = 0; i < s.size(); i++) {
            if(a[goal[i]] == 0 || b[s[i]] == 0) {
                return false;
            }
            if(s[i] != goal[i]) {
                count++;
                a[goal[i]]--;
                b[s[i]]--;
            }
            if(count > 2) return false;
        }
        return count==2;
    }
};