class Solution {
public:
    int getMinSwaps(string num, int k) {
        string str=num;
        int ans=0;
        while(k--)
            next_permutation(str.begin(),str.end());
        
        for(int i=0;i<num.length();i++){
            if(num[i]!=str[i]){
                int j=i+1;
                while(num[j]!=str[i])
                    j++;
                while(j>i)
                {
                    swap(num[j],num[j-1]);
                    j--;
                    ans++;
                    
                }
            }
            cout<<str[i];
        }
        return ans;
    }
};