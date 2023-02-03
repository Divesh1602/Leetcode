class MyCircularDeque {
    private:
    vector<int> v;
    int front;
   
    int size;
    int ct=0;
public:
    MyCircularDeque(int k) {
        v.resize(k);
        front=0;
        size=k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        front=(front+size-1)%size;
        v[front]=value;
        ct++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        int rear=(front+ct)%size;
        v[rear]=value;
        ct++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        front=(front+1)%size;
        ct--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        ct--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return v[front];
    }
    
    int getRear() {
       if(isEmpty())
            return -1;
        int rear=(front+ct-1)%size;
        return v[rear];
    }
    
    bool isEmpty() {
        if(ct==0)
        return true;
        
        return false;
    }
    
    bool isFull() {
        if(ct==size)
        return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */