class Solution {
public:
    int distributeCandies(vector<int>& a) {
        int c=1;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++){
            if(a[i]!=a[i+1])
                c++;
        }
        if(c<a.size()/2)
            return c;
        else
            return a.size()/2;
    }
};