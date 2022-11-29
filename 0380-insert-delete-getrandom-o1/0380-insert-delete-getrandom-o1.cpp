class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int,int> m;
    RandomizedSet() {
        
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            a.push_back(val);
            m[val]++;
        return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){
            auto it=find(a.begin(),a.end(),val);
            a.erase(it);
            m.erase(val);
        return true;
        }
        return false;
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */