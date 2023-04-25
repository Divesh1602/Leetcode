class SmallestInfiniteSet {
    int min;
    map<int,int> mp;
public:
    SmallestInfiniteSet() {
        min=1;
    }
    
    int popSmallest() {
        int k=min;
        mp[min]++;
        while(mp[min]){
            min++;
        }
        return k;
    }
    
    void addBack(int num) {
        if(mp[num]) mp[num]--;
        if(num<min) min=num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */