class CountIntervals {
public:
    map<int,int> m;
    int ct=0;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it=m.lower_bound(left);
        
        while(it!=m.end() && left<=right){
            auto &l=it->second;
            auto &r=it->first;
            if(right < l){
                
                break;
            }
            if(left < l){
                ct+=l-left;
                l=left;
            }
            left=min(r,right)+1;
            it++;
        }
        if(left<=right){
            ct+=right-left+1;
            m[right]=left;
        }
    }
    
    int count() {
        return ct;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */