class Solution {
public:
    bool canConstruct(string str1, string str2) {
      map<char,int> m;
       for(auto x:str2){
           m[x]=m[x]+1;
       }
      
        for(auto x:str1){
           
           m[x]--;
        }
        for(auto x:m){
            if(x.second<0){
                return false;
            }
        }
        return true;
}
};