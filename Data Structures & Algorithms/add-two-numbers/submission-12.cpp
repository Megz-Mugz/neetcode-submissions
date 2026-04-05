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
        ListNode* final_list_ptr{dummy_head};
        
        int ones_carry{0};
        int curr_sum{0};
        // iterate through both LL, and add 2 vals + ones_carry
        while (l1 || l2 || ones_carry){
            
            // add the carry one, and the two current numbers (if they exist)
            curr_sum += ones_carry;
            curr_sum += (l1 ? l1->val : 0);
            curr_sum += (l2 ? l2->val : 0);

            // check the ones digit of current operation
            auto ones_digit = curr_sum % 10;

            // check if we need a carry one for next operation
            ones_carry = (curr_sum > 9 ? 1 : 0);

            // assign the current one's digit to the new node & traverse res LL
            final_list_ptr->next = new ListNode(ones_digit);
            final_list_ptr = final_list_ptr->next;

            // traverse LLs & reset val to 0
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            curr_sum = 0;
        }

        return dummy_head->next;

    }
};
