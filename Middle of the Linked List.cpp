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

// Approach 1: Find the size then find the middle
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int size = 0;
//         ListNode *temp =head;
//         while(temp!=NULL){
//             size++;
//             temp=temp->next;
//         }
//         int middle = size/2;
//         temp=head;
//         while(middle--){
//             temp=temp->next;
//         }
//         return temp;
//     }
// };


// Approach 2: Using Slow and Fast Pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while (fast !=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
       
    }
};
