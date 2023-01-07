class MyHashMap {
public:
    vector<pair<int,int>> m;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        m.push_back({key,value});
    }
    
    int get(int key) {
        for(auto a: m){
            if(a.first==key)
                return a.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index=get(key);
        if(index!=-1){
            for(auto i=m.begin();i!=m.end();i++){
                if(i->first==key){
                    m.erase(i);
                    return;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */