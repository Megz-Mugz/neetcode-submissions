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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy_head(0);
        ListNode* curr_ptr = &dummy_head;

        while (list1 && list2){
            if (list1->val < list2->val){
                curr_ptr->next = list1;
                curr_ptr = curr_ptr->next;
                // move list2 to the next val
                list1 = list1->next;
            } else {
                curr_ptr->next = list2;
                curr_ptr = curr_ptr->next;
                // move list2 to the next val
                list2 = list2->next;
            }
        }

        if (!list1) curr_ptr->next = list2;
        if (!list2) curr_ptr->next = list1;
        

        return dummy_head.next;
    }
};
