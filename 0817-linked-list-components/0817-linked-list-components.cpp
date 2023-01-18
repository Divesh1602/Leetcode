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
    int numComponents(ListNode* head, vector<int>& nums) {
       unordered_map<int,int> m;
        ListNode* curr=head;
        for(auto a: nums)
        m[a]++;
        int ans=0;
     int ct=0;
        while(curr!=NULL){
            if(m[curr->val]!=1 && ct>0){
                ans++;
                ct=0;
            }
            else if(m[curr->val]==1)
                ct++;
            
            curr=curr->next;
        }
        if(ct>0)
            ans++;
        return ans;
    }
};