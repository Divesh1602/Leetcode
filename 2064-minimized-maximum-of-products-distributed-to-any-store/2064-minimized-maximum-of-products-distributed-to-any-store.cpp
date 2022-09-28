class Solution {
public:
    bool isfeasible(int n,vector<int>& a,int ans){
       
        for(int i=0;i<a.size();i++){
            n-=(a[i]/ans);
            if(a[i]%ans!=0)
                n--;
            if(n<0)
                return false;
        }
        return true;
        
    }
    int minimizedMaximum(int n, vector<int>& q) {
     long long int i=1,j=0;
        int res=-1;
        
        for(int a=0;a<q.size();a++){
            j+=q[a];
        }
     
        while(i<=j){
          long long int mid=(i+j)/2;
            if(isfeasible(n,q,mid)){
                res=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return res;
        
    }
};