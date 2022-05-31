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

// Approach 1: Recursive Approach
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *newHead = deleteDuplicates(head->next);
        if(head->val == newHead->val)return newHead;
        else{
            head->next = newHead;
            return head;
        }
    }
};