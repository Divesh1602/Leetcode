class Solution {
public:
    vector<int>parent;
    int find(int key){
        if(key == parent[key]){
            return key;
        }
        return parent[key] = find(parent[key]);
    }
    void myunion(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa == pb){
            return;
        }
        if(pa < pb){
            parent[pb] = pa;
        }
        else{
            parent[pa] = pb;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                myunion((s1[i]-'a'),(s2[i]-'a'));
            }
        }
        string ans = "";
        for(int i=0;i<baseStr.size();i++){
            char a = 'a' + find(baseStr[i]-'a');
            ans.push_back(a);
        }
        return ans;
    }
};