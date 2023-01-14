class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        int n=answers.size();
        unordered_map<int,int> m;
        for(auto a:answers)
            m[a]++;
        for(auto a:m){
            int sum=a.first+1;
            if(sum>=a.second)
                ans+=sum;
            else{
                if(a.second%sum==0){
                    ans+=a.second;
                }
                else{
                    int ct=a.second/sum;
                    int st=sum;
                    sum=ct*sum;
                    ans+=sum+st;
                }
            }
                
        }
        return ans;
    }
};