class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        	int i=0,j=a.size()-1;
        
        vector<int> ans;
        vector<int> nums=a;
        vector<int>::iterator pos;
        sort(a.begin(),a.end());
while(i<j){
	if(a[i]+a[j]==x){
        break;
	}
	else if(a[i]+a[j]<x){
		i++;
	}
	else
	j--;
}
        int b;
        for(int k=0;k<nums.size();k++){
            if(nums[k]==a[i]){
                ans.push_back(k);
            b=k;
                break;
            }
        }
         for(int k=0;k<nums.size();k++){
            if(nums[k]==a[j] && k!=b){
                ans.push_back(k);
                break;
            }
             }
return ans;
    }
    
};