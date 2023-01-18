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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        if(head==NULL)
            return ans;
        ListNode* curr=head;
        int size=0;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
       

       
        if(size>k){
       int mod=size%k;
        size=size/k;
          int i=0;
            if(mod!=0)
            {
                size++;
                mod--;
            }
            else
                mod--;
            curr=head->next;
            int c=1;
            ListNode* temp=new ListNode(head->val);
            ListNode* h=temp;
            while(curr!=NULL){
                if(c==size){
                    ans[i]=h;
                     h=NULL;
                    i++;
                    c=0;
                    if(mod!=0)
            {
               
                mod--;
            }
                    else if(mod==0){
                        size--;
                        mod--;
                    }
                    h=new ListNode(curr->val);
                   
                    temp=h;
                    curr=curr->next;
                }
                else{
                temp->next=new ListNode(curr->val);
                    temp=temp->next;
                curr=curr->next;
                }
                
                c++;
            }
            ans[i]=h;
        }
        else{
            curr=head;
            int i=0;
            while(curr!=NULL){
                ListNode* temp=new ListNode(curr->val);
                ans[i]=temp;
                curr=curr->next;
                i++;
            }
        }
        return ans;
    }
};