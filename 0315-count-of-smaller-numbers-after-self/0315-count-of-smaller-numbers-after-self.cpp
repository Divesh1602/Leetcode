class Solution {
public:
    void merge(vector<pair<int,int>>& v,vector<int>& ans,int left,int mid,int right){
        int i=left,j=mid+1;
        int k=0;
        vector<pair<int,int>> temp(right-left+1);
        while(i<=mid && j<=right){
            if(v[i].first<=v[j].first){
                temp[k]=v[j];
                k++;
                j++;
            }
            else{
                ans[v[i].second]+=right-j+1;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid){
            temp[k++]=v[i++];
        }
        while(j<=right){
             temp[k]=v[j];
                k++;
                j++;
        }
        for(int n=left;n<=right;n++){
            v[n]=temp[n-left];
        }
    }
    
    void mergeSort(vector<pair<int,int>>& v,vector<int>& ans,int i,int j){
        if(i<j){
            int mid=i+(j-i)/2;
            mergeSort(v,ans,i,mid);
            mergeSort(v,ans,mid+1,j);
            merge(v,ans,i,mid,j);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        vector<int> ans(n,0);
        mergeSort(v,ans,0,n-1);
        return ans;
    }
};