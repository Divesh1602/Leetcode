class FreqStack {
    map<int,int> m;
    map<int,stack<int>>ms;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        ms[m[val]].push(val);
    }
    
    int pop() {
        auto it=ms.rbegin();      
        int ans=it->second.top();
        
        ms[m[ans]].pop();
        if(ms[m[ans]].empty())
            ms.erase(m[ans]);
        
         m[ans]--;
        if(m[ans]==0)
            m.erase(ans);
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */