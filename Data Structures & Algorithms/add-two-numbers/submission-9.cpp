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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // dummy
        ListNode* dummy_head = new ListNode(-1);
        ListNode* final_list_ptr = dummy_head;
        // ones_carry = 0
        int ones_carry{};
        int val{};
        // iterate through both LL, and add 2 vals + ones_carry
        while (l1 || l2){

            val = ones_carry;
            val += (l1 ? l1->val : 0);
            val += (l2 ? l2->val : 0);

            auto ones_digit = val % 10;

            // check if we need a carry one for next operation
            ones_carry = (val > 9 ? 1 : 0);

            final_list_ptr->next = new ListNode(ones_digit);
            final_list_ptr = final_list_ptr->next;

            // traverse LLs
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // if the final operation had a carry one, handle as such here
        if (ones_carry){
            final_list_ptr->next = new ListNode(ones_carry);
            final_list_ptr = final_list_ptr->next;
        }

        return dummy_head->next;

    }
};
