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
    ListNode* reverseList(ListNode* head) {
        /*
        0 -> 1 -> 2 -> 3 -> 
        
        prev = nullptr
        curr = head;

        1. temp = cur->next
        2. curr = prev
        move curr's next ptr & prev to the next
        prev = curr
        curr = temp

        return prev since it'll point to last node in LL at the end
        */

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
