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
        /*
            if list1 && list2 && head of list1.val > list2.val:
                add list2 to merged_list_ptr
                move merged_list_ptr next
            else if list1 & list2 && list1.val <= list2.val:
                add list1 to merged_list_ptr
                move merged_list_ptr next
            else if not list1:
                keep adding stuff from list2 to merged_list
            else if not list2:
                keep adding stuff from list1 to merged_list
        
        */

        ListNode dummy_head = ListNode(-1);
        ListNode* merged_list_ptr = &dummy_head;

        while (list1 && list2){
            if (list1->val > list2->val){
                merged_list_ptr->next = list2;
                list2 = list2->next;
            } else {
                merged_list_ptr->next = list1;
                list1 = list1->next;
            }
            merged_list_ptr = merged_list_ptr->next;
        }

        while (!list1 && list2){
            merged_list_ptr->next = list2;
            list2 = list2->next;
            merged_list_ptr = merged_list_ptr->next;
        }

        while (!list2 && list1){
            merged_list_ptr->next = list1;
            list1 = list1->next;
            merged_list_ptr = merged_list_ptr->next;
        }

        return dummy_head.next;
    }
};
