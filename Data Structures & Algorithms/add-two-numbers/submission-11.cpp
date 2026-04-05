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
        int val{0};
        // iterate through both LL, and add 2 vals + ones_carry
        while (l1 || l2 || ones_carry){
            
            val += ones_carry;
            val += (l1 ? l1->val : 0);
            val += (l2 ? l2->val : 0);

            // check the ones digit of current operation
            auto ones_digit = val % 10;

            // check if we need a carry one for next operation
            ones_carry = (val > 9 ? 1 : 0);

            // assign the current one's digit to the new node & traverse res LL
            final_list_ptr->next = new ListNode(ones_digit);
            final_list_ptr = final_list_ptr->next;

            // traverse LLs & reset val to 0
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            val = 0;
        }

        return dummy_head->next;

    }
};
