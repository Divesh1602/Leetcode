/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
       curr=head;
        while(curr!=NULL){
            if(curr->random==NULL)
                curr->next->random=NULL;
            else
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        Node* copy=head->next;
        Node* original=head;
        Node* temp=copy;
        while(original && copy){
             original->next=original->next? original->next->next:NULL;
            original=original->next;
            copy->next=copy->next? copy->next->next:NULL;
           
            copy=copy->next;
            
        }
        return temp;
    }
};