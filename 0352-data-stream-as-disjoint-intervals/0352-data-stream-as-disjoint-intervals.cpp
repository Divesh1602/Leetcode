class SummaryRanges {
public:
    set <int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;

        int start = -1, end = -1;

        for(auto a : s){
            if(start == -1){
                start = a;
                end = a;
            }

            else if(a == end+1){
                end = a;
            }

            else{
                res.push_back({start , end});
                start = a;
                end = a;
            }
        }

        if(start != -1){
            res.push_back({start ,end});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */