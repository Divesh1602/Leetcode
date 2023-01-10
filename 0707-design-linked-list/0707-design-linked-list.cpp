class MyLinkedList {
public:
    MyLinkedList* head;
    MyLinkedList* next;
    int data;
    int size;
    MyLinkedList() {
        head=NULL;
        next=NULL;
        data=-1;
        size=0;
    }
    
    int get(int index) {
        if(index>size)
            return -1;
        MyLinkedList* curr=head;
        int ct=0;
        while(curr!=NULL && ct<index){
            ct++;
            curr=curr->next;
        }
        if(curr!=NULL)
            return curr->data;
        return -1;
    }
    
    void addAtHead(int val) {
        MyLinkedList* temp=new MyLinkedList();
        temp->data=val;
        if(head==NULL){
            head=temp;
            size++;
            return;
        }
        temp->next=head;
        head=temp;
        size++;
        return;
    }
    
    void addAtTail(int val) {
        MyLinkedList* temp=head;
        if(head==NULL){
            addAtHead(val);
            return;
        }
        while(temp->next!=NULL)
            temp=temp->next;
        MyLinkedList* curr=new MyLinkedList();
        curr->data=val;
        temp->next=curr;
        size++;
        return;
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList* temp=new MyLinkedList();
        temp->data=val;
        if(index>size)
            return;
        if(index==0){
            addAtHead(val);
            return;
        }
        int ct=0;
        MyLinkedList* curr=head;
        while(curr!=NULL && ct<index-1){
            ct++;
            curr=curr->next;
        }
        if(curr!=NULL){
            MyLinkedList* t=curr->next;
            curr->next=temp;
            temp->next=t;
            size++;
            return;
        }
    }
    
    void deleteAtIndex(int index) {
        
        if(index>size)
            return;
        if(index==0){
            if(head!=NULL){
                head=head->next;
                size--;
                
            }
            else{
                head=NULL;
                
            }
            return;
        }
        int ct=0;
        MyLinkedList* curr=head;
        while(curr!=NULL && ct<index-1){
            ct++;
            curr=curr->next;
        }
        if(curr->next!=NULL){
            curr->next=curr->next->next;
           size--;
            return;
        }
        else{
            curr->next=NULL;
           
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */