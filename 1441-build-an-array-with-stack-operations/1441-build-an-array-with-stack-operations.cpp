class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int x=1;
        int i=0;
        int size=target.size();
       while(i<size){
            if(target[i]==x){
                ans.push_back("Push");
                i++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            x++;
        }
        return ans;
    }
};