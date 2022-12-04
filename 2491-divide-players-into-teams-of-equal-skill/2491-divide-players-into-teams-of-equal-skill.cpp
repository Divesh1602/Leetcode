class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        long long sum=0;
        for(int i=0;i<n;i++)
            sum+=skill[i];
        
        sort(skill.begin(),skill.end());
        int team=n/2;
        if(sum%team!=0)
            return -1;
        sum=sum/team;
        long long ans=0;
       int i=0,j=n-1;
        while(i<j){
            if(skill[i]+skill[j]!=sum)
                return -1;
            ans+=skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;
        
        
    }
};