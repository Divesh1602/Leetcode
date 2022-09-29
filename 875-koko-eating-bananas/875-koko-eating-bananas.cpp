class Solution {
public:
    bool isfeasible(vector<int>& piles,int h,int ans){
        for(int i=0;i<piles.size();i++){
            h-=piles[i]/ans;
            if(piles[i]%ans!=0){
                h--;
            }
            
             if(h<0)
            return false;
        }
       
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
       long long int j=0;
        int res=INT_MAX;
        for( auto a:piles){
            j+=a;
        }
        
        while(i<=j){
           long long int mid=(i+j)/2;
            if(isfeasible(piles,h,mid)){
                res=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return res;
    }
};