class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()){
            return findMedianSortedArrays(b,a);
            
        }
        int n1=a.size();
        int n2=b.size();
        double res=0;
        int al=0;
        int bl=a.size();
        while(al<=bl){
            int i1=(al+bl)/2;
            int i2=(n1+n2+1)/2-i1;
            int mr1,ml1;
            if(i1==0)
                ml1=INT_MIN;
            else
                ml1=a[i1-1];
            
            if(i1==n1)
                mr1=INT_MAX;
            else
                mr1=a[i1];
            
            int ml2,mr2;
            if(i2==0)
                ml2=INT_MIN;
            else
                ml2=b[i2-1];
            
            if(i2==n2)
                mr2=INT_MAX;
            else
                mr2=b[i2];
                
            if(ml1<=mr2 && ml2<=mr1){
                if((n1+n2)%2!=0){
                    res=max(ml1,ml2);
                    return res;
                }
                else{
                    res=(max(ml1,ml2)+min(mr2,mr1))/2.0;
                    return res;
                }
            }
            else if(ml1>mr2)
                bl=i1-1;
            else
                al=i1+1;
        }
        return 0;
    }
};