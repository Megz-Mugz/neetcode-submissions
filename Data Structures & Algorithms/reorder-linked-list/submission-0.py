# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        slow, fast = head, head
        while (fast != None and fast.next != None):
            slow = slow.next
            fast = fast.next.next

        second_half = slow.next
        slow.next = None  # This cuts off the first half

        
        # reverse second half of linked list
        prev = None
        while (second_half != None):
            temp = second_half.next
            second_half.next = prev
            prev = second_half
            second_half = temp

        orig_list_ptr = head

        while (prev != None):
            temp_manipulated = prev.next
            temp_original = orig_list_ptr.next
            
            orig_list_ptr.next = prev
            prev.next = temp_original

            prev = temp_manipulated
            orig_list_ptr = temp_original
