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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode* odd=head,*temp=head;
        ListNode *even= new ListNode(head->next->val);
        ListNode *ptr=even;
        while(temp and temp->next)
        {
            temp=temp->next;
            odd->next=temp->next;
            odd=odd->next;
            if(temp->next)
            {
                temp=temp->next;
                ptr->next=temp->next;
                ptr=ptr->next;
            }
            else
                break;
        }
        temp=head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=even;
        return head;
    }
};