class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res=INT_MIN;
        for(auto a:strs){
            int ct=0;
            for(int i=0;i<a.length();i++){
                if(isdigit(a[i])==false){
                    ct++;
                    break;
                }
                
            }
            if(ct==1){
                int n=a.length();
                res=max(res,n);
            }
            else{
                int n=stoi(a);
                res=max(res,n);
            }
        }
        return res;
    }
};