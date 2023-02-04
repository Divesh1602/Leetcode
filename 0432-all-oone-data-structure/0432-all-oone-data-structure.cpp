class AllOne {
    set<pair<int,string>> st;
    map<string,int> m;
public:

    AllOne() {
        
    }
    
    void inc(string key) {
       if(m.count(key))
           st.erase({m[key],key});
        st.insert({++m[key],key});
    }
    
    void dec(string key) {
        st.erase({m[key],key});
        if(--m[key])
            st.insert({m[key],key});
    }
    
    string getMaxKey() {
        return st.empty()?"":st.rbegin()->second;
    }
    
    string getMinKey() {
       return st.empty()?"":st.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */