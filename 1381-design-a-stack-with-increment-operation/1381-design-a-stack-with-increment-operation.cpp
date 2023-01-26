class CustomStack {
public:
    int n;
    vector<int> v;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(v.size()>=n){
            return;
        }
        else{
            v.push_back(x);
        }
    }
    
    int pop() {
        int x;
        if(v.size()==0){
            return -1;
        }
        
        else{
          x=v[v.size()-1];
            v.pop_back();
        }
        return x;
    }
    
    void increment(int k, int val) {
      
            int size=v.size();
            int i=0;
            while(i<size && k--){
                v[i]+=val;
                i++;
                
            }
       
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */