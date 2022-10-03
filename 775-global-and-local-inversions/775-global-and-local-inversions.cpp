class Solution {
public:
    
    int mergesort(vector<int>& nums, int &l, int &m, int &r){
        int n1=m-l+1;
        int n2=r-m;
        int l1[n1],r1[n2];
        for(int i=0;i<n1;i++){
            l1[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++){
            r1[i]=nums[m+1+i];
        }
        int i=0,j=0,k=l,res=0;
        while(i<n1 && j<n2){
            if(l1[i]<=r1[j]){
                nums[k]=l1[i];
                i++;
            }
            else{
                nums[k]=r1[j];
                res=res+(n1-i);
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k]=l1[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=r1[j];
            j++;
            k++;
        }
        return res;
    }
    int merge(vector<int>& nums,int l, int r){
       long long int res=0;
        if(l<r){
            int m=l+(r-l)/2;
            res+=merge(nums,l,m);
            res+=merge(nums,m+1,r);
            res+=mergesort(nums,l,m,r);
        }
 
        return res;
    }
    bool isIdealPermutation(vector<int>& nums) {
      
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
                c++;
        }
        int res=merge(nums,0,nums.size()-1);
        if(res==c)
            return true;
        else 
            return false;
    }
};