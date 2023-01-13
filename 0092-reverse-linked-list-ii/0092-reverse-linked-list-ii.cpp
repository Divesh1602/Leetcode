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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos=1;
        ListNode* curr=head;
        vector<int> v;
        while(curr!=NULL && pos<=right){
            if(pos>=left && pos<=right)
                v.push_back(curr->val);
            pos++;
            curr=curr->next;
        }
        reverse(v.begin(),v.end());
        for(auto a:v)
            cout<<a<<" ";
        curr=head;
        pos=1;
        int i=0;
        while(curr!=NULL && pos<=right){
            if(pos>=left && pos<=right){
                curr->val=v[i];
                i++;
            }
            curr=curr->next;
            pos++;
        }
        return head;
    }
};