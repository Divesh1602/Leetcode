class Solution {
public:
    int rev(int x){
        int res=0;
        while(x>0){
            res=res*10+x%10;
            x=x/10;
        }
        return res;
    }
    int countDistinctIntegers(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++){
            int x=rev(a[i]);
            a.push_back(x);
        }
        int ct=1;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++){
           
            while(a[i]==a[i+1]){
                i++;
                if(i>=a.size()-2)
                   return ct;
            }
             if(a[i]!=a[i+1])
                ct++;
        }
        return ct;
    }
};