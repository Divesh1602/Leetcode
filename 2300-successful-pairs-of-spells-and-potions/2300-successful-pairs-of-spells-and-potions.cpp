class Solution {
public:

    int countPairs(int spell, vector<int> &potions, long long success){
        int n = potions.size();
        int index = n;
        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            
            if((long long)potions[mid]*spell >= success){
                index = mid;
                end = mid-1;
            }

           
            if((long long)potions[mid]*spell < success)
                start = mid+1;
        }

        return n-index;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());

       
        sort(potions.begin(), potions.end());

       
        for(int i=0; i<spells.size(); i++)
            ans[i] = countPairs(spells[i], potions, success);

        return ans;
    }
};