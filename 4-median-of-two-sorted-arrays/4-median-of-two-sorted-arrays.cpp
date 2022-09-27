class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       double res=0;
        int sum=nums1.size()+nums2.size();
   int n1=nums1.size();
       int n2=nums2.size();
        if(n1>n2)
           return findMedianSortedArrays(nums2,nums1);
      
        int al=0,bl=n1;
        while(al<=bl){
            int i1=(al+bl)/2;
            int i2=(n1+n2+1)/2-i1;
            double mr1;
            if(i1==n1)
                mr1=INT_MAX;
                else  
                mr1=nums1[i1];
            double ml1;
            if(i1==0)
                ml1=INT_MIN;
                else
                ml1=nums1[i1-1];
           double mr2;
            if(i2==n2)
            mr2=INT_MAX;
            else
            mr2=nums2[i2];
            double ml2;
            if(i2==0)
            ml2=INT_MIN;
            else
            ml2=nums2[i2-1];
          
             
            if(ml1<=mr2 && ml2<=mr1){
                
               
             if(((n1+n2)%2)!=0){
                  res=max(ml1,ml2);
                return res;
              }
              else{
                  res=(max(ml1,ml2)+min(mr2,mr1))/2.0;
            return res;
              }
            }
          
 
             else if(ml1 > mr2){
                bl=i1-1;
            }
            else{
                al=i1+1;
            }
          
          
             
            
        }
        return res;
    }
};