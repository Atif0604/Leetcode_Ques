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

// // Approach 1: Recursive with using the same structure
// class Solution {
// public:
    
//     ListNode* merge(ListNode* l1, ListNode* l2){
//         if(l1==NULL)return l2;
//         if(l2==NULL)return l1;
//         if(l1->val < l2->val){
//             l1->next=merge(l1->next,l2);
//             return l1;
//         }
//         else{
//             l2->next=merge(l1,l2->next);
//             return l2;
//         }
        
//     }
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         return merge(list1,list2);
//     }
// };


// // Approach 2: Iterative with using the same structure (ans LL)
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1==NULL)return list2;
//         if(list2==NULL)return list1;
//         ListNode *ans=NULL,*tail=NULL;
//         if(list1->val < list2->val){
//             ans=list1;
//             tail=list1;
//             list1=list1->next;
            
//         }
//         else{
//             ans=list2;
//             tail=list2;
//             list2=list2->next;
//         }
//         while(list1!=NULL && list2!=NULL){
//         if(list1->val < list2->val){
//             tail->next=list1;
//             tail=list1;
//             list1=list1->next;
            
//         }
//         else{
//             tail->next=list2;
//             tail=list2;
//             list2=list2->next;
//         }
//        }
//         if(list1==NULL) tail->next=list2;
//         else tail->next=list1;
//         return ans;
//     }
// };



// Approach 2.1: Iterative with using the same structure(dummy node)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode *ans=new ListNode(-1);//for making attachment
        ListNode *tail=ans;
        while(list1!=NULL && list2!=NULL){
        if(list1->val < list2->val){
            tail->next=list1;
            tail=list1;
            list1=list1->next;
            
        }
        else{
            tail->next=list2;
            tail=list2;
            list2=list2->next;
        }
       }
        if(list1==NULL) tail->next=list2;
        else tail->next=list1;
        return ans->next;
    }
};