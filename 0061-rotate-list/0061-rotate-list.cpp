/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int size=0;
        ListNode* curr=head;
        ListNode* tail=NULL;
        while(curr!=NULL){
            size++;
            if(curr->next==NULL)
                tail=curr;
            curr=curr->next;
            
        }
        if(head==NULL || size==1 || k==0)
            return head;
        k=k%size;
        if(k==0)
            return head;
        ListNode* temp=head;
        k=size-k;
        while(k>1){
            temp=temp->next;
            k--;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};