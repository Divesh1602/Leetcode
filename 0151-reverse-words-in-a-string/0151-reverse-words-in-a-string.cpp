class Solution {
public:
    string reverseWords(string s) {
//         string ans="";
//         for(int i=s.length()-1;i>=0;i--){
//             string res="";
//             while(s[i]!=' '){
//                 res+=s[i];
//                 i--;
//                 if(i<0)
//                     break;
//             }
//             reverse(res.begin(),res.end());
            
//             if(res.length()>0){
//             ans+=res;
//             ans+=" ";
//             }
//         }
//         int n=ans.length();
//         ans.erase(n-1,n);
       
//         return ans;
        
        vector<string> vec;
        stringstream str(s);
        string word;
        while (str >> word) 
            vec.push_back(word);
        word="";
        reverse(vec.begin(),vec.end());
        for(auto a:vec)
           word+=" "+a;
        word.erase(0,1);
        return word;
    }
};