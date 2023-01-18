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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
        vector<int> v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        vector<int> ans;
        ans.push_back(v[v.size()-1]);
        int mx=v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]>=mx){
                ans.push_back(v[i]);
                mx=v[i];
            }
        }
        reverse(ans.begin(),ans.end());
        curr=new ListNode(ans[0]);
        head=curr;
        for(int i=1;i<ans.size();i++){
            curr->next=new ListNode(ans[i]);
            curr=curr->next;
        }
        return head;
    }
};