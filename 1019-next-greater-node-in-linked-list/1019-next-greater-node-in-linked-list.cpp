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
    ListNode* rev(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        head=rev(head);
        ListNode* curr=head;
        vector<int> ans;
        ans.push_back(0);
        st.push(curr->val);
        curr=curr->next;
        while(curr){
            while(!st.empty() && st.top()<=curr->val)
                st.pop();
            int t=(st.empty())? 0:st.top();
            ans.push_back(t);
            st.push(curr->val);
            curr=curr->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};