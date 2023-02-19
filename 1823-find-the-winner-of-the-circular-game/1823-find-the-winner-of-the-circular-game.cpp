class Solution {
public:
    void helper(vector<int> v,int index,int& ans,int k){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        index=(index+k)%v.size();
        v.erase(v.begin()+index);
        helper(v,index,ans,k);
        return;
    }
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k--;
        int ans=-1;
        helper(v,0,ans,k);
            return ans;
    }
};