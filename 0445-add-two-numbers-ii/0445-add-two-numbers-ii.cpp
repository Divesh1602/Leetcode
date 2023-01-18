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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp;
       
        while(curr!=NULL){
           temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
         ListNode* curr=new ListNode(0);
        ListNode* ans=curr;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            curr->next=temp;
            curr=curr->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int sum=l1->val+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            curr->next=temp;
            curr=curr->next;
            l1=l1->next;
            
        }
        while(l2!=NULL){
            int sum=l2->val+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            curr->next=temp;
            curr=curr->next;
            l2=l2->next;
        }
        if(carry>0){
             ListNode* temp=new ListNode(carry);
            curr->next=temp;
            curr=curr->next;
        }
        ans=ans->next;
        ans=reverseList(ans);
        return ans;
    }
};