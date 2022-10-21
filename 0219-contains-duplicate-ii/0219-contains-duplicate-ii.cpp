class Solution {
public:

    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_set<int> s;
        for(int i=0;i<a.size();i++){
            if(i>k){
                int j=a[i-k-1];
                s.erase(j);
            }
            if(s.count(a[i])>0)
                return true;
            
            s.insert(a[i]);
        }
        return false;
    }
};