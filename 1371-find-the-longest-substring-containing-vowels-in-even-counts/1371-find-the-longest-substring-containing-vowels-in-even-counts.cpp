class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        unordered_map<int,int> m;
        
        m[0]=-1;
        
        int ans=INT_MIN;
        
        int sum=0;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            sum^=s[i];
                
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
                
                }
            
            ans=max(ans,i-m[sum]);
            
        }
        
        return ans;
    }
};