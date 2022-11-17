class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        // if(maxcost==0)
        //     return 1;
        int cost=0;
        int mx=INT_MIN;
        int i=0,j=0;
        while(j<s.length()){
            int diff=abs(s[j]-t[j]);
            cost+=diff;
            
            if(cost>maxcost){
                while(cost>maxcost){
                    int diff=abs(s[i]-t[i]);
                    cost-=diff;
                    i++;
                }
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
        
    }
};