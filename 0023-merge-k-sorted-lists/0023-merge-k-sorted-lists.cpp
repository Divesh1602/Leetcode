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
    ListNode* mergeLists(ListNode* list1,ListNode* list2){
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
          ListNode* head=new ListNode(0);
        ListNode* curr=head;
            
            
        while(list1!=NULL && list2!=NULL){
            
            
            if(list1->val > list2->val){
                curr->next=list2;
                list2=list2->next;
                curr=curr->next;
            }
            
            else{
                curr->next=list1;
                list1=list1->next;
                curr=curr->next;
            }
            
            
        }
        
        
       if(list1!=NULL)
           curr->next=list1;
           
        if(list2!=NULL)
           curr->next=list2;
           
          return head->next;
          
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        
        ListNode* head=mergeLists(lists[0],lists[1]);  
    
       for(int i=2;i<lists.size();i++){
           head=mergeLists(lists[i],head);
          
       }
        return head;
    }
};