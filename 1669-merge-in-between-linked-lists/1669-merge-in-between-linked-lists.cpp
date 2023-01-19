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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int pos=0;
        ListNode* curr=list1;
        while(curr!=NULL){
            if(pos==a-1)
                break;
            curr=curr->next;
            pos++;
        }
        ListNode* temp=curr->next;
        pos++;
        ListNode* head=list2;
        curr->next=head;
        curr=temp;
        while(head->next!=NULL)
            head=head->next;
        while(curr!=NULL){
            if(pos==b)
                break;
            curr=curr->next;
            pos++;
        }
        ListNode* temp1=curr->next;
        curr->next=NULL;
        head->next=temp1;
        return list1;
    }
};