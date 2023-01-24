struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        pre=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> m;
    
    int c,count;
    
    Node* head,*tail;
    
    LRUCache(int capacity) {
        c=capacity;
        count=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->pre=head;
        head->pre=NULL;
        tail->pre=NULL;
    }
    
    
    void deleteNode(Node* temp){
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
    }
    
    
    void addNode(Node* node){
        node->next = head->next; 
		node->next->pre = node; 
		node->pre = head; 
		head->next = node; 
    }
    
    
    int get(int key) {
        
        if(m[key]!=NULL){
            Node* temp=m[key];
            int ans=temp->val;
            deleteNode(temp);
            addNode(temp);
            return ans;
        }
        
        return -1;
    }
    
    
    
    void put(int key, int value) {
        
        if(m[key]!=NULL){
            Node* temp=m[key];
            temp->val=value;
            deleteNode(temp);
            addNode(temp);
        }
        
        else{
            Node* node=new Node(key,value);
            m[key]=node;
            
            if(count<c){
                addNode(node);
                count++;
            }
            
            else{
                m.erase(tail->pre->key);
                deleteNode(tail->pre);
                addNode(node);
            }
            
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */