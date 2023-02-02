class MyCircularQueue {
public:
    list<int> v;
    int size;
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
     if(v.size()<size){
         v.push_back(value);
         
         return true;
     }
        return false;
    }
    
    bool deQueue() {
        if(v.size()==0)
            return false;
        v.pop_front();
        
        return true;
    }
    
    int Front() {
         if(v.size()==0)
            return -1;
       return v.front();
    }
    
    int Rear() {
        if(v.size()==0)
            return -1;
       return v.back();
    }
    
    bool isEmpty() {
        if(v.size()==0)
            return true;
        return false;
    }
    
    bool isFull() {
       if(v.size()==size)
           return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */