class Solution {
public:
    string frequencySort(string s) {
         map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
   
    multimap<int,char> m1;
    for(auto it=m.rbegin();it!=m.rend();it++){
        m1.insert({it->second,it->first});
    }
   
        string res="";
    for(auto a:m1){
        int ocu=a.first;
        for(int i=0;i<ocu;i++){
        res+=a.second;
        }
    }
   reverse(res.begin(),res.end());
        return res;
    }
};