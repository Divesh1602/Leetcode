class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0; 
        unordered_map<int,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
            
        }
        for(auto a:m){
            int st=a.second;
            if(st==1)
                return -1;
            else if(st%3==0)
                ans+=st/3;
            else
                ans+=st/3+1;
        }
        return ans;
    }
};