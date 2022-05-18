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

// Approach 1: Iterative 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *prev=NULL,*curr=head,*next=head->next;
        while(curr != NULL){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next!=NULL) next=next->next;
        }
        return prev;    
    }
};