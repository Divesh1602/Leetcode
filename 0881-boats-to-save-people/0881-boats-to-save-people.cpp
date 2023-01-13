class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size()-1;
        int ans=0;
        int ct=0;
      int i=0;
        int j=n;
        while(i<=j){
            ans=people[i]+people[j];
            if(i==j)
                ans=people[i];
            
            if(ans<=limit){
                
                i++;
                j--;
                
            }
            else if(ans>limit){
                
                j--;
            }
           
             ct++;
        }
        return ct;
    }
    
};