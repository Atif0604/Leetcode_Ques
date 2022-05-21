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
    void reverse(ListNode *start,ListNode *end){
        ListNode *prev=NULL,*current=start,*next=start->next;
        while(prev!=end){
            current->next=prev;
            prev=current;
            current=next;
            if(next!=NULL) next=next->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1){
            return head;
        }
        ListNode *start=head,*end=head;
        int increment=k-1;
        while(increment--){
            end=end->next;
            if(end==NULL)return head;
        }
        ListNode *jointHead=reverseKGroup(end->next,k);
        reverse(start,end);
        start->next=jointHead;
        return end;
    }
};