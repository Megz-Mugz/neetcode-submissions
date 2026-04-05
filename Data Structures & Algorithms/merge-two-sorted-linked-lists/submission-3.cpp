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
        ListNode* dummy_ptr = &dummy_head;

        while (list1 && list2){
            if (list1->val < list2->val){
                dummy_ptr->next = list1;
                list1 = list1->next;
            } else {                
                dummy_ptr->next = list2;
                list2 = list2->next;
            }
            dummy_ptr = dummy_ptr->next;
        }

        if (list1){
            dummy_ptr->next = list1;
        } else {
            dummy_ptr->next = list2;
        }

        return dummy_head.next;
    }
};
