class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int>freqFactor;
        for(auto num : nums)
            primeFactor(num, freqFactor);
        unordered_map<int, int>tillFactor;
        for(int i = 0; i < nums.size(); i++){
            bool flag = true;
            primeFactor(nums[i], tillFactor);
            for(auto fact : tillFactor){
                if(freqFactor[fact.first] - fact.second > 0){
                    flag = false;
                    break;
                }
            }
            if(flag == true && i != nums.size()-1)
                return i;
        }    
        return -1;
    }
    void primeFactor(int num, unordered_map<int, int> &freqFactor) {
        int temp = num;
        for(int i = 2; i*i <= temp; i++){
            while(temp % i == 0){
                freqFactor[i]++;
                temp /= i;
            }
        }
        if(temp > 1)
            freqFactor[temp]++;
    }
};