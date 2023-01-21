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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
         ListNode* curr=head;
        int size=0;
       
        while(curr!=NULL)
        {
            size++;
            curr=curr->next;
        }
        
        ListNode* prevFirst=head;
       
        curr=head->next;
        int ct=1;
        
        int gp=2;
       
        while(curr!=NULL){
            ListNode* first=curr;
            ListNode* prev=NULL;
           int element=size-ct;
         
            int c=0;
           
            if(element>=gp){
           
            
            if(gp%2==0){
            while(curr!=NULL && c<gp){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                c++;
                ct++;
            }
                prevFirst->next=prev;
                prevFirst=first;
            }
                else{
             while(curr!=NULL && c<gp){
                  prev=curr;
               curr=curr->next;
                
                c++;
                ct++;
                }
                    prevFirst->next=first;
                    prevFirst=prev;
            }
            }
            else if(element<gp){
                
                if(element%2==0){
                while(curr!=NULL && c<gp){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                c++;
                ct++;
            }
                prevFirst->next=prev;
                prevFirst=first;
                }
                else{
                     prevFirst->next=curr;
                    curr=NULL;
                }
            }
            gp++;
        }
        return head;
    }
};