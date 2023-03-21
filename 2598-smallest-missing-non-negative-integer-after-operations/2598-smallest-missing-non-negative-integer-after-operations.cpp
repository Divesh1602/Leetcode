class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
           if(nums[i]<0)
               nums[i]=nums[i]%val+val;
            nums[i]=nums[i]%val;
            m[nums[i]]++;
        }
        
        int i=0;
        while(true){
            if(m.find(i)==m.end())
                break;
                int ct=m[i]-1,x=i;
            while(ct--)
            {
                x+=val;
                m[x]++;
            }
            i++;
        }
        return i;
    }
};