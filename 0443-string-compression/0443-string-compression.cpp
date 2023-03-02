class Solution {
public:
    void getVector(vector<char>& c,int x){
        while(x!=0){
            char a=x%10+'0';
            x=x/10;
            c.push_back(a);
        }
        reverse(c.begin(),c.end());
    }
    int compress(vector<char>& chars) {
        if(chars.size()==1)
            return chars.size();
        vector<char> ans;
        int ct=1;
        for(int i=1;i<chars.size();i++){
            
            if(chars[i]!=chars[i-1]){
                if(ct==1){
                    ans.push_back(chars[i-1]);
                    ct=0;
                }
                else{
                    vector<char> c;
                    getVector(c,ct);
                    ans.push_back(chars[i-1]);
                    for(auto a:c)
                        ans.push_back(a);
                    ct=0;
                }
            }
            ct++;
            
        }
        if(chars[chars.size()-1]==chars[chars.size()-2]){
            
            
                    vector<char> c;
                    getVector(c,ct);
                    ans.push_back(chars[chars.size()-1]);
                    for(auto a:c)
                        ans.push_back(a);
                   
                
            }
        
    else{
        ans.push_back(chars[chars.size()-1]);
    }
        
        
        int n=chars.size();
        int i;
        for(i=0;i<ans.size();i++)
            chars[i]=ans[i];
        
        i=n-i;
        while(i--)
            chars.pop_back();
        return chars.size();
        



}  
};