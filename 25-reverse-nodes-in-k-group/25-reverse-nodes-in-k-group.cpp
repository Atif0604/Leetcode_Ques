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

// // Approach 1: Recursive(using extra space)
// class Solution {
// public:
//     void reverse(ListNode *start,ListNode *end){
//         ListNode *prev=NULL,*current=start,*next=start->next;
//         while(prev!=end){
//             current->next=prev;
//             prev=current;
//             current=next;
//             if(next!=NULL) next=next->next;
//         }
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head==NULL||head->next==NULL||k==1){
//             return head;
//         }
//         ListNode *start=head,*end=head;
//         int increment=k-1;
//         while(increment--){
//             end=end->next;
//             if(end==NULL)return head;
//         }
//         ListNode *jointHead=reverseKGroup(end->next,k);
//         reverse(start,end);
//         start->next=jointHead;
//         return end;
//     }
// };


// Approach 2: Iterative(without using extra space)
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
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *beforeStart=dummy,*end=head;
        int counter=0;
        while(end!=NULL){
            counter++;
            if(counter%k==0)
            {
//                 perform reversal and connection makeing
                ListNode *start=beforeStart->next,*temp=end->next;
                reverse(start,end);
                beforeStart->next=end;
                start->next=temp;
                beforeStart=start;
                end=temp;
            }
            else{
                end=end->next;
            }
        }
        return dummy->next;
    }
};