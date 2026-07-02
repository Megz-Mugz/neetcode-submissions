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

        // use dummy head strategy to add nodes to a new linked list
        ListNode dummy_head = ListNode(-1);
        ListNode* merged_list_ptr = &dummy_head;
        
        // when both lists have nodes, add the lesser valued node 
        // as the next item in the merged_list & move the pointer accordingly
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

        // if list1 has no more nodes, but list2 still has nodes, indiscriminately add the
        // nodes from list2 to the merged list and move both pointers accordingly
        while (!list1 && list2){
            merged_list_ptr->next = list2;
            list2 = list2->next;
            merged_list_ptr = merged_list_ptr->next;
        }

        // same logic as above, but when list2 is finished and list1 still has nodes
        while (!list2 && list1){
            merged_list_ptr->next = list1;
            list1 = list1->next;
            merged_list_ptr = merged_list_ptr->next;
        }

        // do not return the dummy head, instead return the node next to the dummy head
        return dummy_head.next;
    }
};
