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
    void reorderList(ListNode* head) {
        // 1. take second part of list & reverse
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // use slow as the prev & reverse after prev
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // break the 2 halves completely

        if (curr) std::cout << curr->val;

        while (curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // 2. then merge
        ListNode* first = head;
        ListNode* second = prev;
        while (second != nullptr){
            // set temp pointers on next vals
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            // make connection on new list
            first->next = second;
            second->next = temp1;
            
            // move pointers on the orig list
            first = temp1;
            second = temp2;

        }
    }
};
