/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                Node* temp=curr->next;
                curr->next=curr->child;
                curr->child->prev=curr;
                curr->child=NULL;
                Node* ptr=curr;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                if(temp!=NULL){
                ptr->next=temp;
                temp->prev=ptr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};