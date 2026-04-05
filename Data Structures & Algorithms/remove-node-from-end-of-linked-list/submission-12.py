# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        curr = head
        size_of_list = 0
        while (curr):
            size_of_list += 1
            curr = curr.next

        prev, curr = None, head
        remaining = size_of_list - n

        while (remaining > 0):
            prev = curr
            curr = curr.next
            remaining -= 1
        
        # if prev is not None, it's a body node, so skip over curr
        if prev: 
            prev.next = curr.next
            curr.next = None # detatch from LL
            return head # return the head of the LL in this case

        return head.next # if prev is None, that means we are removing head, in which case return head.next and continue