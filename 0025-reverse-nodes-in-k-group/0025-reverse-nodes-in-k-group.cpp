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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int size=0;
       
        while(curr!=NULL)
        {
            size++;
            curr=curr->next;
        }
        ListNode* prevFirst=NULL;
        bool chk=true;
        curr=head;
        int ct=0;
        while(curr!=NULL){
           
            int c=0;
            ListNode* first=curr;
            ListNode* prev=NULL;
            while(curr!=NULL && c<k){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                c++;
                ct++;
            }
            if(chk){
                head=prev;
                chk=false;
            }
            else{
                prevFirst->next=prev;
            }
            prevFirst=first;
             if(size-ct<k)
                {
             prevFirst->next=curr;
                 break;
             }
        }
        return head;
    }
};