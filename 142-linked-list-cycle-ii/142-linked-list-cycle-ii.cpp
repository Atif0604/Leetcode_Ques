/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Taking help from LL Cycle1 and
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast == slow){
                break;
            }
        }
        if(fast==NULL || fast->next==NULL)return NULL;// check if loop exist or not
        ListNode *ptr1=head,*ptr2=slow;
        while(ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1; //or ptr2 also can be return
    }
};