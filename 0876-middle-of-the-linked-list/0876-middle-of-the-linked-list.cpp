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
    ListNode* middleNode(ListNode* head) {
        int ct = 0;
        ListNode* node = head;
        while(node != NULL){
            node = node->next;
            ct++;
        }
        node = head;
        int ct1 = 0;
        while(ct1 < ct/2){
            node = node->next;
            ct1++;
        }
        return node;
    }
};