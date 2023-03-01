class Solution {
public:
    void mergeSort(vector<int>& nums,int i,int mid,int j){
        int st=i;
        int en=mid+1;
        vector<int> v;
        while(st<=mid && en<=j){
            if(nums[st]<nums[en])
                v.push_back(nums[st++]);
            else
                v.push_back(nums[en++]);
        }
        
        while(st<=mid)
            v.push_back(nums[st++]);
        while(en<=j)
            v.push_back(nums[en++]);
        
        for(int k=i;k<=j;k++)
            nums[k]=v[k-i];
    }
    void merge(vector<int>& nums,int i,int j){
        if(i<j){
            int mid=i+(j-i)/2;
            merge(nums,i,mid);
            merge(nums,mid+1,j);
            mergeSort(nums,i,mid,j);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};