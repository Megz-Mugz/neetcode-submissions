# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Handle the case where there's only one node in the list
        if head.next is None:
            return None

        # Two-pointer approach to find the nth node from the end
        dummy = ListNode(0)  # Add a dummy node to handle edge cases
        dummy.next = head
        fast = slow = dummy
        
        # Move fast pointer n steps ahead
        for i in range(n):
            fast = fast.next

        # Move both pointers until fast reaches the end
        while fast.next:
            fast = fast.next
            slow = slow.next

        # Remove the nth node
        slow.next = slow.next.next

        return dummy.next


