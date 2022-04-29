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
    int getDecimalValue(ListNode* head) {
      int result= 0;
        ListNode *temp=head;
        while(temp != NULL){
            result *= 2;
            // result += (temp->val)*2^0(i.e 1);
            result += (temp->val);
            temp = temp->next;
        }
        return result;
    }
};
