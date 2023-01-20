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
    ListNode* removeZeroSumSublists(ListNode* head) {
    while(true){
            unordered_map<int,ListNode*> m;
            ListNode* curr=head;
            int sum=0;
        while(curr!=NULL){
            sum+=curr->val;
            if(sum==0){
                head=curr->next;
                curr=curr->next;
                break;
            }
            else if(m.find(sum)!=m.end()){
                ListNode* temp=m[sum];
                temp->next=curr->next;
                curr=curr->next;
                break;
            }
            else{
                m[sum]=curr;
                curr=curr->next;
            }
        }
        if(curr==NULL)
            return head;
    }
        return head;
    }
};