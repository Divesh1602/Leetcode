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


class LFUCache {
public:
    map<int,int> m;
    map<int,pair<Node*,Node*>> freq;
    map<int,pair<int,Node*>> mp;
    
    int c;
    
   
    
    LFUCache(int capacity) {
         c=capacity;
       
    }
    
    
     void deleteNode(Node* temp,int fr){
         Node* head=freq[fr].first;
         Node* tail=freq[fr].second;
         temp->next->pre=temp->pre;
        temp->pre->next=temp->next;
        
         mp.erase(temp->key);
         m[fr]--;
         if(m[fr]==0){
             m.erase(fr);
             freq.erase(fr);
         }
    }
    
    
    void addNode(Node* node,int fr){
        if(m[fr]==0){
            Node* head=new Node(-1,-1);
            Node* tail=new Node(-1,-1);
            head->next=tail;
            tail->pre=head;
            freq[fr].first=head;
            freq[fr].second=tail;
        }
        Node* head=freq[fr].first;
        Node* tail=freq[fr].second;
        node->next = head->next; 
		node->next->pre = node; 
		node->pre = head; 
		head->next = node; 
        m[fr]++;
        mp[node->key]={fr,node};
    }
    
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
          
            Node* temp=mp[key].second;
              int fr=mp[key].first;
            deleteNode(temp,fr);
            addNode(temp,fr+1);
            return temp->val;
       
        
    }
    
    void put(int key, int value) {
        if(c==0)
            return;
         
        if(mp.count(key)){
            Node* temp=mp[key].second;
            int fr=mp[key].first;
            deleteNode(temp,fr);
            addNode(temp,fr+1);
            temp->val=value;
            
        }     
        
            else if(mp.size()==c){
            auto fr = freq.begin()->first;
            Node* node = freq.begin()->second.second;
            deleteNode(node->pre, fr);
            Node* newnode = new Node(key, value);
            addNode(newnode, 1);
            }
            
        else{
                 Node* node=new Node(key,value);
                addNode(node,1);
            }
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */