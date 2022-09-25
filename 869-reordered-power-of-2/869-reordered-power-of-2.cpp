class Solution {
public:
    vector<int> chk(long n){
        vector<int> v(10);
        while(n){
           v[n%10]++;
            n=n/10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
   vector<int> v=chk(n);
        for(int i=0;i<31;i++){
            if(v==chk(1<<i))
                return true;
        }
        return false;
    }
};