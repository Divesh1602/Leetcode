class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res=INT_MAX;
        int i=0,ct=0;
        unordered_set<int> s;
        for(int j=0;j<cards.size();j++){
             ct++;
            if(s.find(cards[j])==s.end())
                s.insert(cards[j]);
           
            else{
                
                while(s.find(cards[j])!=s.end()){
                   
                    s.erase(cards[i]);
                    i++;
                    ct--;
                   
                    
                }
            
                res=min(res,ct+1);
                s.insert(cards[j]);
            }
            
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};