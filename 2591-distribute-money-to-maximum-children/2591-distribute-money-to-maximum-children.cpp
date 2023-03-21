class Solution {
public:
    int distMoney(int money, int children) {
        
        vector<int> v(children,1);
        money-=children;
        if(money<0)
            return -1;
     int ans=0;
        for(int i=0;i<children;i++){
            if(money==0)
                break;
            if(money>=7){
                v[i]+=7;
                money-=7;
                ans++;
            }
            else{
                v[i]+=money;
                money-=v[i]-1;
                
            }
        
        }
        if(money!=0)
            ans--;
        int n=v.size();
        if(v[n-1]==4){
           ans--;
        }
       
        return ans;
    }
};