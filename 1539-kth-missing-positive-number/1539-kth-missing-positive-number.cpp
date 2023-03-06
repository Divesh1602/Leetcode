class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
    vector<int> ans;

        int size = arr.size();

        int j = 0;
        int i = 1;

        while(i < arr[size -1]){

            if( i != arr[j]){

                ans.push_back(i);
            }
            else{

                j++;
            }
            i++;
        }

        if( k <= ans.size()){

            return ans[k-1];
        }
        else{

            int last = arr[arr.size() - 1];
            int value = last + 1;
            int p = ans.size();

            while( p < k){

                ans.push_back(value);
                value++;
                p++;

            }

            return ans[k-1];

        }   
        
    }
};